#include <unistd.h>

void ft_putstr(char* str)
{
    int i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main()
{
    char *empty_string = "\n";
    ft_putstr(empty_string);
    char *one_char_string = "a\n";
    ft_putstr(one_char_string);
    char *long_string = "19-h32blas\n";
    ft_putstr(long_string);
    return 0;
}