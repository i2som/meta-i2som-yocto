#
# Copyright (C) 2017 i2SOM Team.
#

DESCRIPTION = "Recovery system image"
LICENSE = "MIT"

PACKAGE_INSTALL = " \
	busybox \
	parted \
	psplash \
	recovery-initramfs \
	u-boot-fw-utils \
	dbus \
	wipe \
	gptfdisk \
	mmc-utils \
	swupdate \
	util-linux-sfdisk \
	e2fsprogs-mke2fs \
	e2fsprogs-resize2fs \
	mtd-utils-ubifs \
	iperf3 \
	confuse \
	iproute2 \
"

IMAGE_FEATURES = ""
IMAGE_LINGUAS = ""


python() {
	d.setVar('IMAGE_FSTYPES', 'cpio.gz.u-boot ext2.gz')
}

inherit core-image image_types_uboot

IMAGE_ROOTFS_SIZE = "8192"

BAD_RECOMMENDATIONS += " \
	busybox-syslog \
	openssl-conf \
"

#export IMAGE_BASENAME = "i2som-recovery-initramfs"
