#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

void vga_putc(char c);

void vga_clear();

void vga_puts(const char *s);

void vga_put_hex(u32int val);
void vga_put_dec(s32int val);

u8int make_vga_color(u8int bg, u8int fg);
void set_vga_color(u8int col);
u8int get_vga_color();

void move_vga_cursor(u16int x, u16int y);

#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_GREEN 2
#define COLOR_CYAN 3
#define COLOR_RED 4
#define COLOR_MAGENTA 5
#define COLOR_BROWN 6
#define COLOR_GRAY 7
#define COLOR_DARK_GRAY 8
#define COLOR_LIGHT_BLUE 9
#define COLOR_LIGHT_GREEN 10
#define COLOR_LIGHT_CYAN 11
#define COLOR_LIGHT_RED 12
#define COLOR_LIGHT_MAGENTA 13
#define COLOR_YELLOW 14
#define COLOR_WHITE 15

#endif
