# $NetBSD$

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bnlearn.com/
COMMENT=	Bayesian network structure learning, parameter learning and inference

R_PKGNAME=	bnlearn
R_PKGVER=	2.9

LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=  c fortran

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/R-graph/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
