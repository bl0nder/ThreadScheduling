#!/bin/bash
mkdir -p kernel_P2
cd kernel_P2
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.19.9.tar.xz
unxz linux-5.19.9.tar.xz
tar -xvf linux-5.19.9.tar
cd linux-5.19.9
make mrproper
wget -O .config https://raw.githubusercontent.com/bl0nder/ThreadScheduling/main/config-rev-9-gold
make