$NetBSD$

--- deps/v8/src/platform-openbsd.cc.orig	2011-04-13 08:24:41.000000000 +0000
+++ deps/v8/src/platform-openbsd.cc
@@ -164,6 +164,7 @@ void* OS::Allocate(const size_t requeste
 
 
 void OS::Free(void* buf, const size_t length) {
+  // TODO(1240712): munmap has a return value which is ignored here.
   int result = munmap(buf, length);
   USE(result);
   ASSERT(result == 0);
@@ -197,13 +198,7 @@ void OS::Abort() {
 
 
 void OS::DebugBreak() {
-#if (defined(__arm__) || defined(__thumb__))
-# if defined(CAN_USE_ARMV5_INSTRUCTIONS)
-  asm("bkpt 0");
-# endif
-#else
   asm("int $3");
-#endif
 }
 
 
@@ -309,8 +304,30 @@ void OS::SignalCodeMovingGC() {
 
 
 int OS::StackWalk(Vector<OS::StackFrame> frames) {
-  UNIMPLEMENTED();
-  return 1;
+  int frames_size = frames.length();
+  ScopedVector<void*> addresses(frames_size);
+
+  int frames_count = backtrace(addresses.start(), frames_size);
+
+  char** symbols = backtrace_symbols(addresses.start(), frames_count);
+  if (symbols == NULL) {
+    return kStackWalkError;
+  }
+
+  for (int i = 0; i < frames_count; i++) {
+    frames[i].address = addresses[i];
+    // Format a text representation of the frame based on the information
+    // available.
+    SNPrintF(MutableCStrVector(frames[i].text, kStackWalkMaxTextLen),
+             "%s",
+             symbols[i]);
+    // Make sure line termination is in place.
+    frames[i].text[kStackWalkMaxTextLen - 1] = '\0';
+  }
+
+  free(symbols);
+
+  return frames_count;
 }
 
 
@@ -502,6 +519,16 @@ class OpenBSDMutex : public Mutex {
     return result;
   }
 
+  virtual bool TryLock() {
+    int result = pthread_mutex_trylock(&mutex_);
+    // Return false if the lock is busy and locking failed.
+    if (result == EBUSY) {
+      return false;
+    }
+    ASSERT(result == 0);  // Verify no other errors.
+    return true;
+  }
+
  private:
   pthread_mutex_t mutex_;   // Pthread mutex for POSIX platforms.
 };
@@ -571,18 +598,37 @@ Semaphore* OS::CreateSemaphore(int count
 #ifdef ENABLE_LOGGING_AND_PROFILING
 
 static Sampler* active_sampler_ = NULL;
+static pthread_t vm_tid_ = 0;
+
+typedef struct sigcontext ucontext_t;
 
 static void ProfilerSignalHandler(int signal, siginfo_t* info, void* context) {
   USE(info);
   if (signal != SIGPROF) return;
-  if (active_sampler_ == NULL) return;
-
-  TickSample sample;
+  if (active_sampler_ == NULL || !active_sampler_->IsActive()) return;
+  if (vm_tid_ != pthread_self()) return;
 
-  // We always sample the VM state.
-  sample.state = VMState::current_state();
-
-  active_sampler_->Tick(&sample);
+  TickSample sample_obj;
+  TickSample* sample = CpuProfiler::TickSampleEvent();
+  if (sample == NULL) sample = &sample_obj;
+
+  // Extracting the sample from the context is extremely machine dependent.
+  ucontext_t* ucontext = reinterpret_cast<ucontext_t*>(context);
+  sample->state = Top::current_vm_state();
+
+#if V8_HOST_ARCH_IA32
+  sample->pc = reinterpret_cast<Address>(ucontext->sc_eip);
+  sample->sp = reinterpret_cast<Address>(ucontext->sc_esp);
+  sample->fp = reinterpret_cast<Address>(ucontext->sc_ebp);
+#elif V8_HOST_ARCH_X64
+  sample->pc = reinterpret_cast<Address>(ucontext->sc_rip);
+  sample->sp = reinterpret_cast<Address>(ucontext->sc_rsp);
+  sample->fp = reinterpret_cast<Address>(ucontext->sc_rbp);
+#else
+  UNIMPLEMENTED();
+#endif
+  active_sampler_->SampleStack(sample);
+  active_sampler_->Tick(sample);
 }
 
 
@@ -616,6 +662,7 @@ void Sampler::Start() {
   // There can only be one active sampler at the time on POSIX
   // platforms.
   if (active_sampler_ != NULL) return;
+  vm_tid_ = pthread_self();
 
   // Request profiling signals.
   struct sigaction sa;
