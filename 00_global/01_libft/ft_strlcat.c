#include <stdio.h>
#include "libft.h"

size_t ft_strlcat(char* dst, const char* src, size_t dstsize)
{
    size_t dst_len = ft_strlen(dst);
    return ft_strlcpy(dst + dst_len, src, dstsize);
}

int main()
{
    char src[100] = "hello";
    char dst[4] = "wo";
    ft_strlcat(dst, src, 2);
    printf("dst: %s\n", dst);
    return (0);
}