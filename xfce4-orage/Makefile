# $NetBSD: Makefile,v 1.11 2011/04/22 13:44:54 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

ORAGE_VERSION=	4.8.3

DISTNAME=	orage-${ORAGE_VERSION}
PKGNAME=	xfce4-orage-${ORAGE_VERSION}
#PKGREVISION=	1
CATEGORIES=	time
COMMENT=	Xfce time managing application

MASTER_SITES=	http://archive.xfce.org/src/apps/orage/4.8/

CONFIGURE_ARGS+=	--disable-libxfce4mcs

MAKE_DIRS+=	${PREFIX}/libexec/xfce4 ${PREFIX}/libexec/xfce4/panel-plugins
MAKE_DIRS+=	${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/panel-plugins

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../wip/libxfce4ui/buildlink3.mk"
.include "../../wip/xfce4-panel/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
