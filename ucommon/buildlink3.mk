# $NetBSD$

BUILDLINK_TREE+=	ucommon

.if !defined(UCOMMON_BUILDLINK3_MK)
UCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ucommon+=	ucommon>=5.0.6
BUILDLINK_PKGSRCDIR.ucommon?=	../../wip/ucommon

.endif # UCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ucommon
