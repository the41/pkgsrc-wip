# $NetBSD$

BUILDLINK_TREE+=	happy

.if !defined(HAPPY_BUILDLINK3_MK)
HAPPY_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.happy?=	build
BUILDLINK_API_DEPENDS.happy+=	happy>=1.18.9
BUILDLINK_PKGSRCDIR.happy?=	../../wip/happy

.endif	# HAPPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-happy
