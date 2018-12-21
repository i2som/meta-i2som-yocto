#
# Copyright (C) 2017 i2SOM Team.
#
DESCRIPTION = "initramfs for updater of i2S-AM335x."
LICENSE = "MIT"


#DISTRO_FEATURES_remove = " systemd"
#DISTRO_FEATURES_append = " sysvinit"

#VIRTUAL-RUNTIME_init_manager = "sysvinit"
#VIRTUAL-RUNTIME_initscripts = "initscripts"
#DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"


PACKAGE_INSTALL = " \
    base-files \
    base-passwd \
    busybox \
    sysvinit \
    initscripts \
    e2fsprogs-mke2fs \
    mtd-utils-ubifs \
    dosfstools \
    psplash \
    util-linux-sfdisk \
    initramfs-updater \
"
IMAGE_INSTALL = " initramfs-updater "


IMAGE_LINGUAS = " "
IMAGE_ROOTFS_SIZE ?= "8192"

IMAGE_FSTYPES_remove = "ext4"
IMAGE_FSTYPES = " ext2 ext2.gz cpio.gz cpio.gz.u-boot"

BAD_RECOMMENDATIONS += "busybox-syslog"

inherit core-image
inherit image_types_uboot
