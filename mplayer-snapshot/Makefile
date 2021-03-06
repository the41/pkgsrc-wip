# $NetBSD: Makefile,v 1.71 2010/09/05 15:07:39 jakllsch Exp $

PKGNAME=	mplayer-${MPLAYER_VERSION}

COMMENT=	Fast, cross-platform movie player

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/mplayer-snapshot-share/Makefile.common"

USE_TOOLS+=	pkg-config

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
BUILD_DEPENDS+=		yasm-[0-9]*:../../devel/yasm
.endif

CONFIGURE_ARGS+=	--disable-mencoder
CONFIGURE_ARGS+=	--confdir=${PREFIX}/share/mplayer
CONFIGURE_ARGS+=	--enable-xvmc

# Solaris/x86 has Xv, but the header files live in /usr/X11R6, not
# ${X11_BASE}, so we need to also look for headers in this path.
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "i386"
CPPFLAGS+=		-I/usr/X11R6/include
BUILDLINK_PASSTHRU_DIRS+=	/usr/X11R6/include
.endif

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mplayer ${DESTDIR}${PREFIX}/bin

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXvMC/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"

.include "../../graphics/MesaLib/buildlink3.mk"

.include "../../wip/mplayer-snapshot-share/Makefile.depends"

.include "../../mk/bsd.pkg.mk"
.include "../../wip/mplayer-snapshot-share/Makefile.cflags"
