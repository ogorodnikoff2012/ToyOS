#!/bin/bash
# ./update_image.sh
qemu-system-x86_64 -fda floppy.img $@
