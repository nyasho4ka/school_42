#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void* ft_memmove(void* dst, const void* src, size_t len)
{
    char* dst_char = (char*)dst;
    const char* src_char = (char*)src;
    if (dst_char < src_char)
    {
        while (len--)
            *dst_char++ = *src_char++;
    }
    else
    {
        char* dst_last = dst_char + (len - 1);
        const char* src_last = src_char + (len - 1);
        while (len--)
            *dst_last-- = *src_last--;
    }
    return dst;
}
