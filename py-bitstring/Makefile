# $NetBSD$
#

DISTNAME=	bitstring-2.0.1_beta_2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_beta_2//}
CATEGORIES=	devel python
MASTER_SITES=	http://python-bitstring.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/python-bitstring/
COMMENT=	Tools for analysis and modification of binary data in python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED= 27 26

PYDISTUTILSPKG=	yes

DOCDIR=		${PREFIX}/share/doc/py-bitstring

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/bitstring_manual.pdf ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
