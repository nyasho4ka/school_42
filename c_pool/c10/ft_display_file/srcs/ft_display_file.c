#include <unistd.h>
#include <stdio.h>
#include "ft_str.h"
#include "ft_display_file.h"

const int BUFFER_SIZE = 128;

int ft_display_file(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    int char_count = 0;
    do
    {
        char_count = read(fd, buffer, BUFFER_SIZE);
        if (char_count == -1)
            return -1;
        buffer[char_count] = '\0';
        ft_putstr(buffer);

    } while (char_count == BUFFER_SIZE);
    
    return (0);
}
