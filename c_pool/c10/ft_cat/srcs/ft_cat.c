#include <unistd.h>
#include "ft_cat.h"
#include "ft_putstr.h"

void ft_cat(int file_descriptor, char* buff, int buff_size)
{
    int char_count;
    while ((char_count = read(file_descriptor, buff, buff_size)))
    {
        buff[char_count] = '\0';
        ft_putstr(buff, 0);
    }
}