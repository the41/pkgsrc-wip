# $NetBSD$

DISTNAME=	Class-Virtual-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-Virtual/
COMMENT=	Base class for virtual base classes in Perl

DEPENDS+=	p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable
DEPENDS+=	p5-Class-ISA>=0.31:../../devel/p5-Class-ISA
DEPENDS+=	p5-Carp-Assert>=0.10:../../devel/p5-Carp-Assert
BUILD_DEPENDS+=	p5-Test-Simple>=0.50:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Class/Virtual/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
