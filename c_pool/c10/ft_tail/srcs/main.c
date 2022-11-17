#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_atoi.h"
#include "ft_tail.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        return (1);

    char* bytes_count = argv[2];
    char* file_name = argv[3];

    int bytes = ft_atoi(bytes_count);
    int fd = open(file_name, O_RDONLY);

    ft_tail(fd, bytes);
    return (0);
}