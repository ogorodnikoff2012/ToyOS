#include "monitor.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
#define HEX_DIGITS "0123456789ABCDEF"

u16int *VGA = (u16int *)0xb8000;

u16int cursor_x = 0, cursor_y = 0;
u8int current_color = (COLOR_BLACK << 4) | COLOR_WHITE;

u8int make_vga_color(u8int background, u8int foreground) 
{
    return (background << 4) | (foreground & 0x0f);
}

void set_vga_color(u8int color)
{
    current_color = color;
}

u8int get_vga_color()
{
    return current_color;
}

static u16int make_vga_entry(u8int col, char c)
{
    u16int ret = col;
    ret <<= 8;
    ret |= c;
    return ret;
}

static void move_cursor()
{
    u16int cursor_location = cursor_y * SCREEN_WIDTH + cursor_x;
    outb(0x3d4, 14);
    outb(0x3d5, cursor_location >> 8);
    outb(0x3d4, 15);
    outb(0x3d5, cursor_location);
}

void move_vga_cursor(u16int x, u16int y) 
{
    cursor_x = x;
    cursor_y = y;
    move_cursor();
}

static void scroll()
{
    if (cursor_y >= SCREEN_HEIGHT) 
    {
        u16int blank = make_vga_entry(current_color, ' ');
        int i;
        for (i = 0; i < (SCREEN_HEIGHT - 1) * SCREEN_WIDTH; ++i)
        {
            VGA[i] = VGA[i + SCREEN_WIDTH];
        }
        for (i = (SCREEN_HEIGHT - 1) * SCREEN_WIDTH; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
        {
            VGA[i] = blank;
        }
        cursor_y = SCREEN_HEIGHT - 1;
    }
}

void vga_putc(char c) 
{
    if (c == '\n')
    {
        do
        {
            vga_putc(' ');
        }
        while (cursor_x != 0); 
    }
    else if (c == '\r')
    {
        cursor_x = 0;
    }
    else if (c == '\t')
    {
        while ((cursor_x & 7) != 0)
        {
            vga_putc(' ');
        }
    }
    else if (c == '\b')
    {
        if (cursor_x > 0) 
        {
            cursor_x--;
            vga_putc(' ');
            cursor_x--;
        }
    }
    else 
    {
        u16int entry = make_vga_entry(current_color, c);
        VGA[cursor_x + cursor_y * SCREEN_WIDTH] = entry;
        cursor_x++;

        if (cursor_x >= SCREEN_WIDTH) 
        {
            cursor_x = 0;
            cursor_y++;
            scroll();
        }
    }
    move_cursor();
}

void vga_clear()
{
    u16int entry = make_vga_entry(current_color, ' ');
    int i;
    for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i)
    {
        VGA[i] = entry;
    }
    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

void vga_puts(char *s)
{
    while (*s != 0)
    {
        vga_putc(*s++);
    }
}

void vga_put_hex(u32int val)
{
    vga_puts("0x");
    int i;
    for (i = 28; i >= 0; i -= 4)
    {
        vga_putc(HEX_DIGITS[(val >> i) & 0x0F]);
    }
}

void vga_put_dec(s32int val)
{
    if (val < 0) 
    {
        vga_putc('-');
        val = -val;
    }
    if (val >= 10)
    {
        vga_put_dec(val / 10);
    }
    vga_putc('0' + (val % 10));
}
