#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft.h"

// void ft_convert_to_written_value(char* value, char* dict_path)
// {
    
// }

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return 1;

    // char* value = argc == 2 ? argv[1] : argv[2];
    char* dict_path = argc == 2 ? "numbers.dict" : argv[1];
    // ft_convert_to_written_value(value, dict_path);
    int fd = open(dict_path, O_RDONLY);
    t_fstream* fstream = create_fstream(fd);
    int status = 0;
    t_numbers_dict* dict = create_dict(50); 

    char *line;
    while (status != -1)
    {
        line = ft_getline(fstream, &status);
        add_elem(dict, line);
    }
    print_dict(dict);
    return (0);
}