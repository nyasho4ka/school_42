#include <unistd.h>

void ft_putstr(char *c)
{
    int i = 0;
    while (*(c + i) != '\0')
    {
        i++;
    }
    write(1, c, i);
}

int main()
{
    char c[4] = "lol\n";
    ft_putstr(c);
    return 0;
}