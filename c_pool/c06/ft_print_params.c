#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_param(char* param)
{
    int char_count = 0;
    while (param[char_count])
    {
        char_count++;
    }
    write(1, param, char_count);
    ft_putchar('\n');
}

void ft_print_params(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
        ft_print_param(argv[i]);
}

int main(int argc, char** argv)
{
    if (argc > 1)
        ft_print_params(argc, argv);
    return (0);
}