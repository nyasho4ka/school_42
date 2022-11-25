#include <string.h>
#include <stdio.h>
#include "libft.h"

char* ft_strnstr(const char* haystack, const char* needle, size_t len)
{
    size_t needle_len = ft_strlen(needle);
    size_t search_len = len >= needle_len ? len - needle_len + 1 : 0;
    while (search_len--)
    {
        if (ft_memcmp(haystack, needle, needle_len) == 0)
            return (char*)haystack;
        haystack++;
    }
    return (void*)(0);
}
