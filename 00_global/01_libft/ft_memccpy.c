#include "libft.h"

void* ft_memccpy(void* dst, const void* src, int c, size_t n)
{
    const unsigned char* src_char = (const unsigned char*) src;
    unsigned char* dst_char = (unsigned char*) dst;
    unsigned char chr = (unsigned char)c;

    size_t i = 0;
    while (i < n)
    {
        dst_char[i] = src_char[i];
        if (src_char[i++] == chr)
            break;
    }
    return dst + i;
}
