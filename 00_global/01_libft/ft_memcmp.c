#include <stdio.h>
#include "libft.h"

int ft_memcmp(const void* s1, const void* s2, size_t n)
{
    const unsigned char* s1_ch = (const unsigned char*)s1;
    const unsigned char* s2_ch = (const unsigned char*)s2;
    while(n-- && s1_ch && s2_ch)
    {
        if (*s1_ch != *s2_ch)
            return (int)(*s1_ch - *s2_ch);
        s1_ch++;
        s2_ch++;
    }
    return 0;
}
