# $NetBSD$
#

DISTNAME=	aspell6-te-0.01-2
PKGNAME=	${DISTNAME:S/aspell6/aspell/:C/te-(.*)-(.*)$/telugu-\1.\2/}
#PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=aspell/dict/te/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prudhvi-krishna-bsd@surapaneni.in
HOMEPAGE=	http://www.swecha.org/wiki/Wordlist_and_Dictionaries
COMMENT=	Telugu language support for aspell

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
