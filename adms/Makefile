# $NetBSD: Makefile,v 1.42 2008/02/02 04:50:20 10.50 Exp $
#

DISTNAME=		adms-2.2.8
CATEGORIES=		cad
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mot-adms/}
SUBDIR+=		adms

MAINTAINER=		10.50@free.fr
HOMEPAGE=		http://mot-adms.sourceforge.net/
COMMENT=		Verilog to C code compiler

#PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison flex autoconf automake
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++ fortran77

#LDFLAGS+= ${COMPILER_RPATH_FLAG}${PREFIX}/lib

pre-configure:
	cd ${WRKSRC} && autoreconf -f

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
