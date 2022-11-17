#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "ft_cat.h"
#include "ft_putstr.h"

const int BUFF_SIZE = 1024;
char buff[BUFF_SIZE + 1];

int main(int argc, char **argv)
{
    (void)argc;
    // interactive mode
    if (argc == 1)
        ft_cat(0, buff, BUFF_SIZE);
    // per file mode
    else
    {
        for (int i = 1; i < argc; i++)
        {
            int fd = open(argv[i], O_RDONLY);
            if (fd == -1)
            {
                char* error_msg = strerror(ENOENT);
                ft_putstr(error_msg, 1);
                return (ENOENT);
            }
            ft_cat(fd, buff, BUFF_SIZE);
        }
    }
    return (0);
}