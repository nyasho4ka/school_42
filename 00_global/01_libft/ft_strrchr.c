#include "libft.h"

char* ft_strrchar(const char* s, int c)
{
    size_t s_len = ft_strlen(s) + 1;
    char c_ch = (char)c;
    while (s_len--)
    {
        if (s[s_len] == c_ch)
            return (char*)(s + s_len);
    }
    return (void*)(0);
}
