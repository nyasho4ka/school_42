#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void* ft_memset(void *b, int c, unsigned int len)
{
    unsigned char* char_b = (unsigned char*) b;
    unsigned int i = 0;
    while (i < len)
    {
        char_b[i] = (unsigned char)c;
        i++;
    }
    return b;
}
