#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_tail.h"

const int BUFFER_SIZE = 1024;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_swap_buffers(char** buffers)
{
    char* tmp_buff = buffers[0];
    buffers[0] = buffers[1];
    buffers[1] = tmp_buff;
}

void ft_tail(int file_descriptor, int bytes_count)
{
    int actual_buffer_size = BUFFER_SIZE >= bytes_count ? BUFFER_SIZE : bytes_count;
    char** buffers = (char**)malloc(sizeof(char*) * 2);

    for (int i = 0; i < 2; i++)
        buffers[i] = (char*)malloc(sizeof(char) * actual_buffer_size);

    int count = 0;
    int res = 0;
    do
    {
        res = read(file_descriptor, buffers[0], actual_buffer_size);
        if (res == -1)
            break;
        count = res;
        ft_swap_buffers(buffers);
    } while (count == actual_buffer_size);

    if (count == 0)
        return;

    if (count >= bytes_count)
    {
        for (int i = count - bytes_count; i < count; i++)
            ft_putchar(buffers[1][i]);
    }
    else
    {
        int rest_bytes = bytes_count - count;
        if (rest_bytes > 0)
        {
            for (int i = actual_buffer_size - rest_bytes; i < actual_buffer_size; i++)
            ft_putchar(buffers[0][i]);
        }

        for (int i = 0; i < count; i++)
            ft_putchar(buffers[1][i]);
    }
}