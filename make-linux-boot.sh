#!/bin/bash

LINUX_KERNEL_DIR=${PWD}
LINUX_HWPACK_OUT=$LINUX_KERNEL_DIR/output

make rk3288-MiQi_defconfig
make -j8 rk3288-MiQi.img
make -j8 modules

./mkbootimg --kernel arch/arm/boot/zImage \
    --ramdisk rootfs.cpio.gz  \
    --second resource.img \
    --output linux-boot.img


if [ -d ${LINUX_HWPACK_OUT} ]; then
    rm -rf ${LINUX_HWPACK_OUT}
fi

mkdir ${LINUX_HWPACK_OUT}
make INSTALL_MOD_PATH=${LINUX_HWPACK_OUT} modules_install
make INSTALL_FW_PATH=${LINUX_HWPACK_OUT}/lib/firmware firmware_install

KERNEL_VER=`make kernelrelease`
(
  cd ${LINUX_HWPACK_OUT}/lib/modules/${KERNEL_VER}
  rm build source
  ln -s /usr/src/linux-rockchip build
  ln -s /usr/src/linux-rockchip source
)
