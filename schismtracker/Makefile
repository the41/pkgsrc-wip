# $NetBSD$
#

DISTNAME=	schismtracker-0.5rc1
CATEGORIES=	audio
MASTER_SITES=	http://rigelseven.com/schism/dl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lars.nordlund@hem.utfors.se
HOMEPAGE=	http://rigelseven.com/schism/
COMMENT=	Music tracker similar to Impulse Tracker

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/SDL/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
