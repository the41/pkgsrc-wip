# $NetBSD$

DISTNAME=		stunnel-3.26
PKGREVISION=		4
CATEGORIES=		security
MASTER_SITES=		http://www.stunnel.org/download/stunnel/src/

MAINTAINER=		hauke@NetBSD.org
HOMEPAGE=		http://www.stunnel.org/
COMMENT=		Universal SSL tunnel
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	sbin lib ${PKGMANDIR}/man8 share/doc/stunnel3

CONFLICTS=		stunnel-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q} \
			--with-cert-dir=${SSLCERTS:Q} \
			--with-pem-dir=${SSLCERTS:Q} \
			--with-tcp-wrappers

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stunnel ${DESTDIR}/${PREFIX}/sbin
	${INSTALL_LIB} ${WRKSRC}/stunnel.so ${DESTDIR}/${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/stunnel.8 \
			${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/doc/english/VNC_StunnelHOWTO.html \
			${DESTDIR}/${PREFIX}/share/doc/stunnel3
	${INSTALL_DATA} ${WRKSRC}/doc/english/transproxy.txt \
			${DESTDIR}/${PREFIX}/share/doc/stunnel3

.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
