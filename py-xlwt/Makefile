# $NetBSD$
#

VERS=					0.7.2
DISTNAME=				xlwt-${VERS}
PKGNAME=				${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=				1
CATEGORIES=				textproc
MASTER_SITES=			http://pypi.python.org/packages/source/x/xlwt/

MAINTAINER=				helgoman@users.sourceforge.net
HOMEPAGE=				https://secure.simplistix.co.uk/svn/xlwt/trunk/
COMMENT=				Library to create spreadsheet files

LICENSE=				original-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=			yes
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
