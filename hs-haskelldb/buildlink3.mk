# $NetBSD$

BUILDLINK_TREE+=	hs-haskelldb

.if !defined(HS_HASKELLDB_BUILDLINK3_MK)
HS_HASKELLDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-haskelldb+=	hs-haskelldb>=0.12
BUILDLINK_PKGSRCDIR.hs-haskelldb?=	../../wip/hs-haskelldb

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_HASKELLDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-haskelldb
