require recipes-images/images/i2som-headless-image.bb

SUMMARY =  "This image supports Qt graphics libraries"

IMAGE_FEATURES += "splash ssh-server-openssh hwcodecs qtcreator-debug"

LICENSE = "MIT"

inherit distro_features_check populate_sdk_qt5

CONFLICT_DISTRO_FEATURES = "x11 wayland"

IMAGE_INSTALL += "\
    packagegroup-base \
    packagegroup-qt \
"
