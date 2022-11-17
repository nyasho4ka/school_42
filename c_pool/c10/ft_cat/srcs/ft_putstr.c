#include <unistd.h>
#include "ft_putstr.h"

void ft_putstr(char* str, int witn_new_line)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    write(1, str, i);
    if (witn_new_line)
    {
        char c = '\n';
        write(1, &c, 1);
    }
}