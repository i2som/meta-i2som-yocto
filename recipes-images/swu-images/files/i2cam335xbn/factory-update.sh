if [ "$1" == "preinst" ]; then
   echo "Link update devices"
   ln -sf /dev/mtd0 /dev/spl1
   ln -sf /dev/mtd1 /dev/spl2
   ln -sf /dev/mtd2 /dev/uboot1
   ln -sf /dev/mtd3 /dev/uboot2
   ln -sf /dev/mtd6 /dev/linux1
   ln -sf /dev/mtd7 /dev/linux2
   ln -sf /dev/mtd9 /dev/rootfs1
fi
