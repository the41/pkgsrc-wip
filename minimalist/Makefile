# $NetBSD$
#

DISTNAME=	minimalist-2.5.3
CATEGORIES=	mail
MASTER_SITES=	http://www.mml.org.ua/LIST/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.mml.org.ua/
COMMENT=	Minimalistic Mailing Lists Manager

USE_TOOLS+=	perl
REPLACE_PERL=	${WRKSRC}/minimalist.pl
REPLACE_PERL+=	${WRKSRC}/contrib/minimalist_request.pl

EGDIR=		${PREFIX}/share/examples/minimalist/
CONF_FILES=	${EGDIR}/minimalist.conf ${PKG_SYSCONFDIR}/minimalist.conf

SUBST_CLASSES+=	path
SUBST_STAGE.path=post-patch
SUBST_FILES.path=minimalist.conf-sample
SUBST_FILES.path+=minimalist.pl
SUBST_FILES.path+=contrib/minimalist_request.pl
SUBST_SED.path= -e 's,/usr/local,${PREFIX},'

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/minimalist/sample
	# cfgfiles
	${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample \
		${PREFIX}/etc/minimalist.conf
	${INSTALL_DATA} ${WRKSRC}/minimalist.conf-sample \
		${PREFIX}/share/examples/minimalist/minimalist.conf
	# examples
	${INSTALL_DATA} ${WRKSRC}/sample/lists.lst \
		${PREFIX}/share/examples/minimalist/
	${INSTALL_DATA} ${WRKSRC}/sample/sample/* \
		${PREFIX}/share/examples/minimalist/sample/
	# documentation
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/minimalist/FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ/* \
		${PREFIX}/share/doc/minimalist/FAQ/
.for _file_ in README CHANGES.txt virtual-domains.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${_file_} \
		${PREFIX}/share/doc/minimalist/
.endfor
	# scripts
	${INSTALL_SCRIPT} ${WRKSRC}/minimalist.pl \
			${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/minimalist_request.pl \
			${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
