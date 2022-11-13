#ifndef __FT_PUTCHAR__
#define __FT_PUTCHAR__
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}
#endif