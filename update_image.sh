#!/bin/bash

echo "Mount floppy"
sudo losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 /mnt
echo "Copy kernel"
sudo cp src/kernel /mnt/kernel
echo "Unmount floppy"
sudo umount /dev/loop0
sudo losetup -d /dev/loop0
echo "Done"
