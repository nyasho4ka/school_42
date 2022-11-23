#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void ft_bzero(void* s, unsigned int n)
{
    ft_memset(s, 0, n);
}
