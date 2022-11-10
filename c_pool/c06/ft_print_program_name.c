#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_program_name(char* name)
{
    int i = 0;
    while (name[i])
    {
        ft_putchar(name[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    (void) argc;
    char *program_name = argv[0];
    ft_print_program_name(program_name);
    return (0);
}