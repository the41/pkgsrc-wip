# $NetBSD$
#

DISTNAME=	FeynHiggs-2.7.3
PKGNAME=	${DISTNAME:S/F/f/S/H/h/}
CATEGORIES=	physics
MASTER_SITES=	http://wwwth.mppmu.mpg.de/members/heinemey/feynhiggs/newversion/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.feynhiggs.de/FeynHiggs.html
COMMENT=	Fortran code for the diagrammatic calculation of the masses
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=NO

GNU_CONFIGURE=	yes
MAKE_FILE=	makefile
USE_LANGUAGES=	c c++ fortran

INSTALLATION_DIRS= share/doc/feynhiggs ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/man/api.pdf ${DESTDIR}${PREFIX}/share/doc/feynhiggs
	${INSTALL_DATA} ${WRKSRC}/man/man1/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
