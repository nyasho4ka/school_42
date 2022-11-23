#include "libft.h"

void* ft_memset(void *b, int c, size_t len)
{
    unsigned char* char_b = (unsigned char*) b;
    size_t i = 0;
    while (i < len)
    {
        char_b[i] = (unsigned char)c;
        i++;
    }
    return b;
}
