#ifndef LOGGER_H
#define LOGGER_H

#include "common.h"
#include "monitor.h"

#define LOG(s) vga_putc('\n'); vga_puts("KERNEL " __FILE__ ":"); \
    vga_put_dec(__LINE__); vga_puts(", in function "); \
    vga_puts(__func__); vga_puts(": "); vga_puts(s); 

#endif // LOGGER_H

