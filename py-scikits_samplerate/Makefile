# $NetBSD$
#

DISTNAME=	scikits.samplerate-0.3.3
PKGNAME=	${PYPKGPREFIX}-scikits_samplerate-0.3.3
CATEGORIES=	audio
MASTER_SITES=	http://pypi.python.org/packages/source/s/scikits.samplerate/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.ar.media.kyoto-u.ac.jp/members/david/softwares/samplerate
COMMENT=	Python module for high quality audio resampling
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/scikits.samplerate-0.3.3

do-test:
	${RUN} cd ${WRKSRC}/scikits/samplerate/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_regression.py

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
