#include "libft.h"

void* ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char* s_ch = (const unsigned char*)s;
    while (n-- && s_ch)
    {
        if (*s_ch == (unsigned char)c)
            return (void*)s_ch;
        s_ch++;
    }
    return (void*)(0);
}
