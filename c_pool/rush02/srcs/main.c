#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_fstream.h"
#include "ft_numbers_dict.h"
#include "ft_converter.h"
#include "ft_str.h"

// void ft_convert_to_written_value(char* value, char* dict_path)
// {
    
// }

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return 1;

    char* value = argc == 2 ? argv[1] : argv[2];
    char* dict_path = argc == 2 ? "numbers.dict" : argv[1];

    int fd = open(dict_path, O_RDONLY);
    t_fstream* fstream = create_fstream(fd);
    int status = 0;
    t_numbers_dict* dict = create_dict(41);
    char *line;
    while (status != -1)
    {
        line = ft_getline(fstream, &status);
        if (ft_strlen(line) > 0)
            add_elem(dict, line);
    }

    printf("%s\n", ft_convert(value, dict));
    free_dict(dict);
    return (0);
}