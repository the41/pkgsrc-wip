# $NetBSD$
#

DISTNAME=	innotop-1.7.2
CATEGORIES=	wip databases
MASTER_SITES=	http://innotop.googlecode.com/files/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/innotop/
COMMENT=	MySQL and InnoDB monitor program
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Term-ReadKey>=2.10:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=	p5-DBD-mysql>=1.0:../../databases/p5-DBD-mysql

PERL5_PACKLIST=	auto/innotop/.packlist
REPLACE_PERL=	innotop
NO_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
