# $NetBSD$
#

DISTNAME=	gemrb-0.6.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gemrb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gemrb.sourceforge.net/
COMMENT=	Open Source clone of the Infinity Engine
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

BUILDLINK_TRANSFORM+=	rm:-Werror
CMAKE_ARGS+=		-DINSOURCEBUILD=1
CMAKE_ARGS+=		-DSDLMIXER_INCLUDE_DIR=${BUILDLINK_PREFIX.SDL_mixer}/include
INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/gemrb

#.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
# not properly found by cmake?
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
