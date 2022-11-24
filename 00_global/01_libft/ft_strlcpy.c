#include "libft.h"

size_t ft_strlcpy(char* dst, const char* src, size_t dstsize)
{
    size_t src_len = ft_strlen(src);
    if (src_len < dstsize)
    {
        ft_memcpy(dst, src, dstsize + 1);
    }
    else if (dstsize != 0)
    {
        ft_memcpy(dst, src, dstsize - 1);
        dst[dstsize] = '\0';
    }
    return src_len;
}
