# $NetBSD$

DISTNAME=		gtk2-engines-magicchicken_1.1.1.orig
PKGNAME=		gtk2-engines-magicchicken-1.1.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.debian.org/debian/pool/main/g/gtk2-engines-magicchicken/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://art.gnome.org/
COMMENT=		MagicChicken theme engine for GTK+ 2.x

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES
WRKSRC=			${WRKDIR}/gtk2-engines-magicchicken-1.1.1.orig

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
