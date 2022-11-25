#include "libft.h"

char* ft_strchr(const char* s, int c)
{
    size_t s_len = ft_strlen(s);
    char c_ch = (char)c;
    if (c_ch == '\0')
        return (char*)(s + s_len);
    return (char*)ft_memchr(s, c, s_len);
}
