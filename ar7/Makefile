# $NetBSD$

DISTNAME=	ar7-0.1
CATEGORIES=	net
MASTER_SITES=	http://home.arcor.de/volpol/ar7/ \
		ftp://ftp.backschues.net/pub/driver/sphairon_ar860/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	${MASTER_SITES}
COMMENT=	Diagnosis tool for certain ADSL modems
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
INSTALLATION_DIRS=	bin

USE_FEATURES+=	getopt_long
LIBS.SunOS+=	-lnsl -lsocket

.include "../../mk/bsd.pkg.mk"
