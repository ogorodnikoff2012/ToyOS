#include "common.h"
#include "monitor.h"

int kernel_main(struct multiboot *mboot_ptr)
{
    set_vga_color(make_vga_color(COLOR_BLUE, COLOR_WHITE));
    vga_clear();
    vga_puts("\n\n>>>\tHello ToyOS!");
    return 0xDEADBABA;
}
