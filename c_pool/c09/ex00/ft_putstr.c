#ifndef __FT_PUTSTR__
#define __FT_PUTSTR__
void ft_putchar(char c);

void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str++);
    }
}
#endif