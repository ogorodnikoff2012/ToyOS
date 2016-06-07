#include "common.h"
#include "monitor.h"
// #include "int32_test.h"
#include "descriptor_tables.h"
#include "timer.h"

int kernel_main(struct multiboot *mboot_ptr)
{
    // int32_test();
    set_vga_color(make_vga_color(COLOR_BLUE, COLOR_WHITE));
    vga_clear();

    init_descriptor_tables();
    init_timer(DEFAULT_FREQUENCY);

    vga_puts("\n\n>>>\tHello ToyOS!\n\n");
    vga_puts("kernel_main() addr: ");
    vga_put_hex((u32int)kernel_main);
    vga_putc('\n');

    asm volatile ("int $0x3");
    asm volatile ("int $0x4");

    return 0xDEADBABA;
}
