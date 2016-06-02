#include "common.h"
#include "isr.h"
#include "logger.h"

void isr_handler(registers_t regs)
{
    LOG("Recieved interrupt ");
    vga_put_dec(regs.int_no);
}
