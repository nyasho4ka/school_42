#include "libft.h"

size_t ft_strlcat(char* dst, const char* src, size_t dstsize)
{
    size_t dst_len = ft_strlen(dst);
    return ft_strlcpy(dst + dst_len, src, dstsize - dst_len);
}
