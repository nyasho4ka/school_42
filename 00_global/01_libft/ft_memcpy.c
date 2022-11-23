#include "libft.h"

void* ft_memcpy(void* dst, const void* src, size_t n)
{
    if (src == (void*)(0) || dst == (void*)(0))
        return (void*)(0);

    unsigned char* dst_char = (unsigned char*)dst;
    const unsigned char* src_char = (const unsigned char*)src;

    size_t i = 0;
    while (i < n)
    {
        dst_char[i] = src_char[i];
        i++;
    }
    return dst;
}
