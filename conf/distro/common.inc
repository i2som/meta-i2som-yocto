DISTRO_VERSION ??= "UNASSIGNED"
DISTRO_VERSION_ti33x = "2.2"
VENDOR = "i2SOM"
TARGET_VENDOR = "-${VENDOR}"

SDK_VENDOR = "-${VENDOR}sdk"
SDK_VERSION := "${DISTRO_VERSION}"
SDK_NAME = "${VENDOR}-${DISTRO}-${TCLIBC}-${SDK_ARCH}-${IMAGE_BASENAME}-${TUNE_PKGARCH}"
SDKPATH = "/opt/${VENDOR}-${DISTRO}/${SDK_VERSION}"

#activate config checker
INHERIT += "sanity"

#run QA tests on builds and packages and log them
INHERIT += "insane"
QA_LOG = "1"

# Prelink images
INHERIT += "image-prelink"

# optimize lib sizes with mklibs
INHERIT += "image-mklibs"

#run QA tests on recipes
#INHERIT += "recipe_sanity"

PACKAGE_CLASSES ?= "package_rpm"


# Uncomment below lines to enable systemd

#DISTRO_FEATURES_remove = "sysvinit"
#DISTRO_FEATURES += "systemd"
#VIRTUAL-RUNTIME_init_manager = "systemd"
#PREFERRED_PROVIDER_udev = "systemd"
#DISTRO_FEATURES_BACKFILL_CONSIDERED += "sysvinit"
#PREFERRED_PROVIDER_udev-utils = "systemd"
