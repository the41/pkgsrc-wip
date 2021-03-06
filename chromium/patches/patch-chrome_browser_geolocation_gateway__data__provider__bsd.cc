$NetBSD$

--- chrome/browser/geolocation/gateway_data_provider_bsd.cc.orig	2011-04-26 05:17:13.000000000 +0000
+++ chrome/browser/geolocation/gateway_data_provider_bsd.cc
@@ -0,0 +1,188 @@
+// Copyright (c) 2010 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// Provides MAC addresses of connected routers by using the /proc/net/
+// directory which contains files with network information.
+// This directory is used in most BSD based operating systems.
+
+#include "chrome/browser/geolocation/gateway_data_provider_bsd.h"
+
+#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+#include <sys/time.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/route.h>
+#include <net/ethernet.h>
+#include <netinet/in.h>
+#include <netinet/if_ether.h>
+#include <arpa/inet.h>
+#include <string.h>
+#include <unistd.h>
+#include <stdlib.h>
+
+#include <algorithm>
+#include <set>
+#include <string>
+#include <vector>
+
+#include "base/command_line.h"
+#include "base/utf_string_conversions.h"
+#include "chrome/browser/geolocation/empty_device_data_provider.h"
+#include "chrome/browser/geolocation/gateway_data_provider_common.h"
+#include "chrome/common/chrome_switches.h"
+
+#ifndef SA_SIZE
+#define SA_SIZE(sa)						\
+	((!(sa) || ((struct sockaddr *)(sa))->sa_len == 0) ?	\
+	 sizeof(long) :						\
+	 1 + ( (((struct sockaddr *)(sa))->sa_len - 1) | (sizeof(long) - 1)))
+#endif
+
+namespace {
+
+// TODO(joth): Cache the sets of gateways and MAC addresses to avoid reading
+// through the arp table when the routing table hasn't changed.
+class BSDGatewayApi : public GatewayDataProviderCommon::GatewayApiInterface {
+ public:
+  BSDGatewayApi() {}
+  virtual ~BSDGatewayApi() {}
+
+  static BSDGatewayApi* Create() {
+    return new BSDGatewayApi();
+  }
+
+  // GatewayApiInterface
+  virtual bool GetRouterData(GatewayData::RouterDataSet* data);
+
+ private:
+  DISALLOW_COPY_AND_ASSIGN(BSDGatewayApi);
+};
+
+bool GetGateways(std::set<std::string>* gateways) {
+  struct rt_msghdr *rtm;
+  size_t needed;
+  int mib[6];
+  char *buf, *next, *lim;
+
+  struct sockaddr *dst;
+  struct sockaddr_inarp *gw;
+
+  mib[0] = CTL_NET;
+  mib[1] = PF_ROUTE;
+  mib[2] = 0;
+  mib[3] = AF_INET;
+  mib[4] = NET_RT_DUMP;
+  mib[5] = 0;
+
+  if (sysctl(mib, 6, NULL, &needed, NULL, 0) > 0) 
+    return false;
+
+  if ((buf = (char *)malloc(needed)) == 0)
+    return false;
+
+  if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0)
+    return false;
+
+  lim = buf + needed;
+  for (next = buf; next < lim; next += rtm->rtm_msglen) {
+    rtm = (struct rt_msghdr *) next;
+    if (!(rtm->rtm_flags & RTF_GATEWAY))
+      continue;
+
+    dst = (struct sockaddr *)(rtm + 1);
+    gw = (struct sockaddr_inarp *)(dst->sa_len + (char *)dst);
+
+    gateways->insert(inet_ntoa(gw->sin_addr));
+
+  }
+  free(buf);
+  return true;
+}
+
+// Gets a RouterDataSet containing MAC addresses related to any connected
+// routers. Returns false if we cannot read the arp file.
+// The /proc/net/arp file contains arp data in the following format
+// Note: "|" represents a delimeter.
+// IP address|HW type|Flags|HW address|Mask|Device
+// The delimiter for this table is " ".
+bool GetMacAddresses(GatewayData::RouterDataSet* data,
+                     std::set<std::string>* gateways) {
+  struct rt_msghdr *rtm;
+  size_t needed;
+  int    mib[6];
+  char  *buf, *next, *lim;
+
+  struct sockaddr_inarp *sin;
+  struct sockaddr_dl *sdl;
+
+  mib[0] = CTL_NET;
+  mib[1] = PF_ROUTE;
+  mib[2] = 0;
+  mib[3] = AF_INET;
+  mib[4] = NET_RT_FLAGS;
+  mib[5] = 0;
+
+  if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
+    return false;
+
+  if ((buf = (char *)malloc(needed)) == 0)
+    return false;
+
+  if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0)
+    return false;
+
+  lim  = buf + needed;
+  for (next = buf; next < lim; next += rtm->rtm_msglen) {
+    rtm = (struct rt_msghdr *)next;
+    sin = (struct sockaddr_inarp *)(rtm + 1);
+
+    std::string ip_addr = inet_ntoa(sin->sin_addr);
+    if (gateways->find(ip_addr) == gateways->end())
+      continue;
+
+    sdl = (struct sockaddr_dl *)((char *)sin + SA_SIZE(sin));
+    std::string mac_addr = ether_ntoa((struct ether_addr *)LLADDR(sdl));
+
+    std::replace(mac_addr.begin(), mac_addr.end(), ':', '-');
+    RouterData router;
+    router.mac_address = UTF8ToUTF16(mac_addr);
+    data->insert(router);
+  }
+
+  return true;
+}
+
+bool BSDGatewayApi::GetRouterData(GatewayData::RouterDataSet* data) {
+  std::set<std::string> gateways;
+  if (!GetGateways(&gateways))
+    return false;
+  if (gateways.empty())
+    return true;
+  return GetMacAddresses(data, &gateways);
+}
+} // namespace
+
+// static
+template<>
+GatewayDataProviderImplBase* GatewayDataProvider::DefaultFactoryFunction() {
+  if (!CommandLine::ForCurrentProcess()
+      ->HasSwitch(switches::kExperimentalLocationFeatures))
+    return new EmptyDeviceDataProvider<GatewayData>();
+  return new GatewayDataProviderBSD();
+}
+
+GatewayDataProviderBSD::GatewayDataProviderBSD() {
+}
+
+GatewayDataProviderBSD::~GatewayDataProviderBSD() {
+}
+
+GatewayDataProviderCommon::GatewayApiInterface*
+    GatewayDataProviderBSD::NewGatewayApi() {
+  return BSDGatewayApi::Create();
+}
