#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "common.h"

void init_keyboard();

#define PIC_KEYBOARD_STATUS_PORT 0x64
#define PIC_KEYBOARD_DATA_PORT 0x60

#endif // KEYBOARD_H
