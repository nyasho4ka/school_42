#include <unistd.h>
#include "ft_str.h"

void ft_putstr(char* str)
{
    int size = 0;
    while (str[size])
        size++;
    write(1, str, size);
}
