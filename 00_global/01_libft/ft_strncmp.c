#include <stdio.h>
#include <string.h>
#include "libft.h"

int ft_strncmp(const char* s1, const char* s2, size_t n)
{
    if (n == 0) return (0);

    unsigned char* s1_u = (unsigned char*)s1;
    unsigned char* s2_u = (unsigned char*)s2;

    for (size_t i = 0; i < n; i++)
    {
        if (s1_u[i] != s2_u[i] || !s1_u[i])
            return (int)(s1_u[i] - s2_u[i]);
    }
    return (int)(s1_u[n - 1] - s2_u[n - 1]);
}
