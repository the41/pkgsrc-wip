# $NetBSD$

BUILDLINK_TREE+=	linux-attr

.if !defined(LINUX_ATTR_BUILDLINK3_MK)
LINUX_ATTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linux-attr+=	linux-attr>=2.4.32.1
BUILDLINK_PKGSRCDIR.linux-attr?=	../../wip/linux-attr
.endif # LINUX_ATTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-linux-attr
