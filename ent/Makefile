# $NetBSD$
#

DISTNAME=		random
PKGNAME=		ent-19981020
CATEGORIES=		security
MASTER_SITES=		http://fourmilab.ch/random/
EXTRACT_SUFX=		.zip

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://fourmilab.ch/random/
COMMENT=		Entropy calculation and analysis of putative random sequences

WRKSRC=		${WRKDIR}
BUILD_TARGET=	${EMPTY}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ent ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
