# $NetBSD$

BUILDLINK_TREE+=	spandsp

.if !defined(SPANDSP_BUILDLINK3_MK)
SPANDSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spandsp+=	spandsp>=0.0.6pre12
BUILDLINK_ABI_DEPENDS.spandsp?=	spandsp>=0.0.6pre12nb1
BUILDLINK_PKGSRCDIR.spandsp?=	../../wip/spandsp

.include "../../graphics/tiff/buildlink3.mk"
.endif # SPANDSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-spandsp
