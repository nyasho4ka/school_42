#include <fcntl.h>
#include <unistd.h>
#include "ft_str.h"
#include "ft_display_file.h"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc == 1)
    {
        char* missing_file_error = "File name missing\n";
        ft_putstr(missing_file_error);
        return (1);
    }
    if (argc > 2)
    {
        char* too_many_args_error = "Too many arguments\n";
        ft_putstr(too_many_args_error);
        return (2);
    }
    char* file_name = argv[1];
    int fd = open(file_name, O_RDONLY);

    if (fd == -1 || ft_display_file(fd) == -1)
    {
        char* cannot_read_error = "Cannot read file\n";
        ft_putstr(cannot_read_error);
        return (3);
    }
    close(fd);
    return (0);
}