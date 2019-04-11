if [ "$1" == "preinst" ]; then
   echo "Partition the eMMC device"
   
   dd if=/dev/zero of=/dev/mmcblk1 bs=1K count=2048
   echo "Write bootloader"
   dd if=/run/media/mmcblk0p1/boot/MLO of=/dev/mmcblk1 obs=128K seek=1
   dd if=/run/media/mmcblk0p1/boot/u-boot.img of=/dev/mmcblk1 obs=384K seek=1
   
   parted -s /dev/mmcblk1 --script mklabel gpt

   parted -s /dev/mmcblk1 --script mkpart primary fat16 1MiB 51MiB
   parted -s /dev/mmcblk1 --script mkpart primary fat16 51MiB 101MiB
   parted -s /dev/mmcblk1 --script mkpart primary fat16 101MiB 151MiB
   parted -s /dev/mmcblk1 --script mkpart primary ext4 151MiB 651MiB
   parted -s /dev/mmcblk1 --script mkpart primary ext4 651MiB 1151MiB
   parted -s /dev/mmcblk1 --script mkpart primary ext4 1151MiB 2151MiB
   parted -s /dev/mmcblk1 --script mkpart primary ext4 2151MiB 3151MiB
   parted -s /dev/mmcblk1 --script print

   mkfs.vfat /dev/mmcblk1p1
   mkfs.vfat /dev/mmcblk1p2
   mkfs.vfat /dev/mmcblk1p3
   mkfs.ext4 -F /dev/mmcblk1p4
   mkfs.ext4 -F /dev/mmcblk1p5
   mkfs.ext4 -F /dev/mmcblk1p6
   mkfs.ext4 -F /dev/mmcblk1p7

   ln -sf /dev/mmcblk1p1 /dev/linux_a
   ln -sf /dev/mmcblk1p4 /dev/rootfs_a
   ln -sf /dev/mmcblk1p5 /dev/rootfs_b

    echo 0 > /sys/block/mmcblk1boot0/force_ro
fi

if [ "$1" == "postinst" ]; then
   resize2fs /dev/mmcblk1p4
   resize2fs /dev/mmcblk1p5
   
   echo 1 > /sys/block/mmcblk1boot0/force_ro
    
fi
