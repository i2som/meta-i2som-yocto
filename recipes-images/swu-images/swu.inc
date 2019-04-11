# Copyright (C) 2017 i2SOM Team.

SUMMARY = "Generate update package for SWUpdate"
SECTION = "base"
LICENSE = "GPL-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI = "file://sw-description"
SRC_URI_append_i2cam335xbe = " file://factory-update.sh"
SRC_URI_append_i2cam335xbn = " file://factory-update.sh"

inherit swupdate

IMAGE_DEPENDS = "${@get_baseimg_pn(d)}"

IMG_NAME = "${IMAGE_DEPENDS}"

SWUPDATE_IMAGES = "${IMG_NAME}"

SOFTWARE_VERSION ?= "0.0.1"

BOOTFS_EXT ?= ""
ROOTFS_EXT_i2cam335xbn ?= ".ubi"

BOOTFS_EXT_i2cam335xbe ?= ".boot.vfat"
ROOTFS_EXT_i2cam335xbe ?= ".ext4"

BOOT_DEV_NAME ?= "/dev/mtd_kernel"
ROOTFS_DEV_NAME ?= "/dev/mtd_rootfs"

SPL_IMG_EXT = ""
UBOOT_IMG_EXT = ""
LINUXFIT_EXT = ""

SPL_IMG_EXT_i2cam335xbn = ".boot.mlo"
UBOOT_IMG_EXT_i2cam335xbn = ".boot.uboot"
LINUXFIT_EXT_i2cam335xbn ?= ".linux.fit"

SPL1_DEV_NAME_i2cam335xbn ?= "/dev/spl1"
SPL2_DEV_NAME_i2cam335xbn ?= "/dev/spl2"
UBOOT1_DEV_NAME_i2cam335xbn ?= "/dev/uboot1"
UBOOT2_DEV_NAME_i2cam335xbn ?= "/dev/uboot2"
LINUX1_DEV_NAME_i2cam335xbn ?= "/dev/linux1"
LINUX2_DEV_NAME_i2cam335xbn ?= "/dev/linux2"
ROOTFS1_DEV_NAME_i2cam335xbn ?= "/dev/rootfs1"
ROOTFS2_DEV_NAME_i2cam335xbn ?= ""

BOOT1_DEV_NAME_i2cam335xbe ?= "/dev/mmcblk1p1"
BOOT2_DEV_NAME_i2cam335xbe ?= "/dev/mmcblk1p2"
ROOTFS1_DEV_NAME_i2cam335xbe ?= "/dev/mmcblk1p4"
ROOTFS2_DEV_NAME_i2cam335xbe ?= "/dev/mmcblk1p5"

ROOTFS_ENC_DEV = "${ROOTFS_DEV_NAME}"
ROOTFS_DEV_NAME_FINAL = "${ROOTFS_DEV_NAME}"
PREINST_SCRIPT_TEMPLATE_EMMC = "scripts: ( { filename = \"factory-update.sh\"; type = \"shellscript\"; sha256 = \"@factory-update.sh\"; \\x7D );"
PREINST_SCRIPT_TEMPLATE_NAND = "scripts: ( { filename = \"factory-update.sh\"; type = \"shellscript\"; sha256 = \"@factory-update.sh\"; \\x7D );"
PREINST_SCRIPT_DESC = ""
PREINST_SCRIPT_DESC_i2cam335xbn = "${PREINST_SCRIPT_TEMPLATE_NAND}"
PREINST_SCRIPT_DESC_i2cam335xbe = "${PREINST_SCRIPT_TEMPLATE_EMMC}"

python () {
    img_fstypes = d.getVar('BOOTFS_EXT', True) + " " + d.getVar('ROOTFS_EXT', True) + " " + d.getVar('SPL_IMG_EXT', True) + " " + d.getVar('UBOOT_IMG_EXT', True) + " " + d.getVar('LINUXFIT_EXT', True)
    d.setVarFlag("SWUPDATE_IMAGES_FSTYPES", d.getVar('IMG_NAME', True), img_fstypes)
}

def get_baseimg_pn(d):
    file_name = d.getVar('PN', True)
    return file_name[:file_name.find("-swu")]

    #do_unpack[postfuncs] += "fill_description"
do_unpack[postfuncs] += " ${@bb.utils.contains("MACHINE_ARCH", "i2cam335xbe", "fill_description_i2cam335xbe", "fill_description_i2cam335xbn", d)} "

fill_description_i2cam335xbe() {

	sed -i -e "s,##BOOTIMG_NAME##,${IMG_NAME}-${MACHINE}${BOOTFS_EXT},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##BOOT1_DEV##,${BOOT1_DEV_NAME},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##BOOT2_DEV##,${BOOT2_DEV_NAME},g" "${WORKDIR}/sw-description"

	sed -i -e "s,##ROOTIMG_NAME##,${IMG_NAME}-${MACHINE}${ROOTFS_EXT},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##ROOTFS1_DEV##,${ROOTFS1_DEV_NAME},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##ROOTFS2_DEV##,${ROOTFS2_DEV_NAME},g" "${WORKDIR}/sw-description"
	
    sed -i -e "s,##SW_VERSION##,${SOFTWARE_VERSION},g" "${WORKDIR}/sw-description"
	sed -i -e "s/##PREINSTALL_SCRIPT##/${PREINST_SCRIPT_DESC}/g" "${WORKDIR}/sw-description"
}

fill_description_i2cam335xbn() {

	sed -i -e "s,##SPLIMG_NAME##,${IMG_NAME}-${MACHINE}${SPL_IMG_EXT},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##SPL1_DEV##,${SPL1_DEV_NAME},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##SPL2_DEV##,${SPL2_DEV_NAME},g" "${WORKDIR}/sw-description"
	
    sed -i -e "s,##UBOOTIMG_NAME##,${IMG_NAME}-${MACHINE}${UBOOT_IMG_EXT},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##UBOOT1_DEV##,${UBOOT1_DEV_NAME},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##UBOOT2_DEV##,${UBOOT2_DEV_NAME},g" "${WORKDIR}/sw-description"
	
	sed -i -e "s,##LINUXIMG_NAME##,${IMG_NAME}-${MACHINE}${LINUXFIT_EXT},g" "${WORKDIR}/sw-description"
    sed -i -e "s,##LINUX1_DEV##,${LINUX1_DEV_NAME},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##LINUX2_DEV##,${LINUX2_DEV_NAME},g" "${WORKDIR}/sw-description"

	sed -i -e "s,##ROOTIMG_NAME##,${IMG_NAME}-${MACHINE}${ROOTFS_EXT},g" "${WORKDIR}/sw-description"
	sed -i -e "s,##ROOTFS1_DEV##,${ROOTFS1_DEV_NAME},g" "${WORKDIR}/sw-description"
	
    sed -i -e "s,##SW_VERSION##,${SOFTWARE_VERSION},g" "${WORKDIR}/sw-description"
	sed -i -e "s/##PREINSTALL_SCRIPT##/${PREINST_SCRIPT_DESC}/g" "${WORKDIR}/sw-description"
}
