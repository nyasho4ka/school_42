#include <unistd.h>
#include "ft_char_to_hex.h"

const char HEX_MAP[] = "0123456789abcdef";

static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void print_char_to_hex(char c)
{
    int hex_num[2];
    int digit = 0;
    while (c)
    {
        hex_num[digit] = c % 16;
        c = c / 16;
        digit++;
    }
    for (int i = 1; i >= 0; i--)
    {
        ft_putchar(HEX_MAP[hex_num[i]]);
    }
}

void ft_print_hex_content(const char *str, unsigned int char_num, unsigned int space_num)
{
    int is_first = 1;
    for (unsigned int i = 0; i < char_num; i++)
    {
        if (is_first)
        {
            is_first = 0;
        }
        else
        {
            ft_putchar(' ');
        }
        print_char_to_hex(str[i]);
    }

    for (unsigned int i = 0; i < space_num; i++)
    {
        ft_putchar(' ');
        ft_putchar(' ');
        ft_putchar(' ');
    }
}

static int is_printable(char c)
{
    return c >= 32 && c <= 127;
}

void ft_print_char_content(const char* str, unsigned int char_num, unsigned int space_num)
{
    ft_putchar(' ');
    ft_putchar('|');
    for (unsigned int i = 0; i < char_num; i++)
    {
        if (is_printable(str[i]))
            ft_putchar(str[i]);
        else
            ft_putchar('.');
    }
    
    for (unsigned int i = 0; i < space_num; i++)
        ft_putchar(' ');
    ft_putchar('|');
    ft_putchar('\n');
}