#include <unistd.h>
#include <fcntl.h>
#include "ft_char_to_hex.h"

const int CHUNK_SIZE = 16;

int main(int argc, char **argv)
{
    if (argc == 1)
        return (0);

    char* file_name = argv[1];
    char buffer[16];
    int fd = open(file_name, O_RDONLY);
    int char_count = 0;
    while ((char_count = read(fd, buffer, 16)) > 0)
    {
        unsigned int char_num = CHUNK_SIZE > char_count ? char_count : CHUNK_SIZE;
        unsigned int space_num = CHUNK_SIZE - char_num;
        ft_print_hex_content(buffer, char_num, space_num);
        ft_print_char_content(buffer, char_num, space_num);
    }
}