# $NetBSD$

DISTNAME=	spfmilter-1.0.8
CATEGORIES=	mail
MASTER_SITES=	http://www.libspf2.org/patch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libspf2.org/
COMMENT=	Implementation of the Sender Policy Framework (SPF) as a milter

GNU_CONFIGURE=	YES
PTHREAD_OPTS+=	require
RCD_SCRIPTS=	spfmilter

BUILDLINK_API_DEPENDS.libmilter?=	libmilter>=8.13.0

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libspf2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
