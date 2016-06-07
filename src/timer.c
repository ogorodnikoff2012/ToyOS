#include "timer.h"
#include "isr.h"
#include "logger.h"
#include "monitor.h"

u32int tick = 0;

static void timer_callback(registers_t regs)
{
    tick++;
//    LOG("Tick: ");
//    vga_put_dec(tick);
//    vga_putc(' ');
}

void init_timer(u32int freq)
{
    register_interrupt_handler(IRQ0, &timer_callback);

    u32int divisor = 1193180 / freq; // MAGIC 
    outb(0x43, 0x36);

    u8int l = (u8int)(divisor & 0xff);
    u8int h = (u8int)((divisor >> 8) & 0xff);
    
    outb(0x40, l);
    outb(0x40, h);

    LOG("PIT ready");
}

u32int uptime()
{
    return tick;
}
