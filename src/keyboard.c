#include "keyboard.h"
#include "logger.h"
#include "monitor.h"
#include "isr.h"

static void kbd_handler(registers_t regs)
{
    u8int status, code;
    status = inb(PIC_KEYBOARD_STATUS_PORT);
    code = inb(PIC_KEYBOARD_DATA_PORT);
    LOG("Kbd ");
    vga_put_dec(status);
    vga_putc(' ');
    vga_put_hex(code);
}

void init_keyboard()
{
   register_interrupt_handler(IRQ1, kbd_handler);
   LOG("Keyboard ready");
}
