# $NetBSD$
#

DISTNAME=	java-cup-11a-runtime
PKGNAME=	${DISTNAME:S/-runtime//}
CATEGORIES=	textproc java
MASTER_SITES=	http://www2.cs.tum.edu/projects/cup/
EXTRACT_SUFX=	.jar

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www2.cs.tum.edu/projects/cup/
COMMENT=	LALR parser generator for java

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/java-cup-11a-runtime.jar

USE_JAVA=	run
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC} ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
