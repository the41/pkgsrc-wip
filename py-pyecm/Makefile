# $NetBSD$
#

DISTNAME=	pyecm-2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pyecm/pyecm/2.0/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://garr.dl.sourceforge.net/project/pyecm/pyecm/2.0/
COMMENT=	Integer factorization with the Elliptic Curve Method (ECM)
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=yes

REPLACE_PYTHON+= pycem.py

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pyecm.py ${DESTDIR}${PREFIX}/bin/pycem

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
