#ifndef LOGGER_H
#define LOGGER_H

#include "common.h"
#include "monitor.h"
#include "timer.h"

#define LOG(s) vga_puts("\n["); vga_put_dec(uptime()); \
    vga_puts("\t] KERNEL " __FILE__ ":"); \
    vga_put_dec(__LINE__); vga_puts(", in function "); \
    vga_puts(__func__); vga_puts(": "); vga_puts(s); 

#endif // LOGGER_H

