# $NetBSD$
#

DISTNAME=		PyPE1.8.2
PKGNAME=		${PYPKGPREFIX}-PyPE-1.8.2
WRKSRC=			${WRKDIR}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pype/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pype.sourceforge.net/
COMMENT=		Lightweight, but powerful editor for Python

DEPENDS=	${PYPKGPREFIX}-wxWidgets>=2.4.2.4:../../x11/py-wxWidgets

PYTHON_PATCH_SCRIPTS=	pype.py
NO_BUILD=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PY_PATCHPLIST=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PYSITELIB}/pype
	${INSTALL_DATA} ${WRKSRC}/configuration.py \
		${PREFIX}/${PYSITELIB}/pype/configuration.py
	${INSTALL_DATA} ${WRKSRC}/parsers.py \
		${PREFIX}/${PYSITELIB}/pype/parsers.py
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${PREFIX}/${PYSITELIB}/pype/readme.txt
	${INSTALL_DATA} ${FILESDIR}/__init__.py \
		${PREFIX}/${PYSITELIB}/pype/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/pype.py ${PREFIX}/bin/pype.py-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
