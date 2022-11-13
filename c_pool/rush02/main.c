#include <unistd.h>
#include <stdio.h>


void ft_convert_to_written_value(char* value, char* dict_path)
{
    
}

int main(int argc, char **argv)
{
    if (argc != 2 || argc != 3)
        return 1;

    char* value = argc == 2 ? argv[1] : argv[2];
    char* dict_path = argc == 2 ? "numbers.dict" : argv[1];
    ft_convert_to_written_value(value, dict_path);
    
    return (0);
}