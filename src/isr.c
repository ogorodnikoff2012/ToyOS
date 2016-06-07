#include "common.h"
#include "isr.h"
#include "logger.h"

isr_t interrupt_handlers[256];

void register_interrupt_handler(u8int n, isr_t handler)
{
    interrupt_handlers[n] = handler;
}

void isr_handler(registers_t regs)
{
    LOG("Recieved interrupt ");
    vga_put_dec(regs.int_no);
    vga_putc(' ');
    vga_put_dec(regs.err_code);
}

void irq_handler(registers_t regs)
{
    if (regs.int_no >= 40)
    {
        outb(0xA0, 0x20);
    }
    outb(0x20, 0x20);

    if (interrupt_handlers[regs.int_no] != 0)
    {
        isr_t handler = interrupt_handlers[regs.int_no];
        handler(regs);
    }
}
