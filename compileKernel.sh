#!/bin/bash
mkdir -p kernel1
cd kernel1
cp ../linux-5.19.9.tar .
tar -xvf linux-5.19.9.tar
cd linux-5.19.9
make mrproper
cp ../../config-rev-9-gold .config
make