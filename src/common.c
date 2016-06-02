#include "common.h"

void outb(u16int port, u8int value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
    u8int ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

u16int inw(u16int port)
{
    u16int ret;
    asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

void memcpy(u8int *dest, const u8int *src, u32int len)
{
    if (dest < src)
    {
        int i;
        for (i = 0; i < len; i++) 
        {
            dest[i] = src[i];
        }
    }
    else
    {
        int i;
        for (i = len - 1; i >= 0; i--)
        {
            dest[i] = src[i];
        }
    }
}

void memset(u8int *dest, u8int val, u32int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        dest[i] = val;
    }
}

int strcmp(char *str1, char *str2)
{
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != 0)
    {
        i++;
    }
    return ((int)str1[i] - (int)str2[i]);
}

char *strcpy(char *dest, const char *src)
{
    memcpy((u8int *)dest, (u8int *)src, (strlen(src) + 1) * sizeof(char));
    return dest;
}

char *strcat(char *dest, const char *src)
{  
    memcpy((u8int *)(dest + strlen(dest)), (u8int *)src, (strlen(src) + 1) * sizeof(char));
    return dest;
}

int strlen(const char *src)
{
    int i = 0;
    while (src[i] != 0) 
    {
        i++;
    }
    return i;
}
