# $NetBSD: Makefile,v 1.6 2011/04/22 13:42:21 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	xfconf-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	Xfce client-server configuration storage and query system

XFCE4_PROJECT=  xfconf
XFCE4_BRANCH=   4.8
XFCE4_VERSION=	4.8.1

PKGCONFIG_OVERRIDE=	xfconf/libxfconf-0.pc.in

CONFIGURE_ARGS+=	--disable-perl-bindings

MAKE_DIRS+=	${PREFIX}/include/xfce4

BUILDLINK_API_DEPENDS.dbus+=		dbus>=1.0.0
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.72

.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
