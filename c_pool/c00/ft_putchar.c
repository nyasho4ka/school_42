#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}


int main()
{
    // Output is a
    ft_putchar(97);
    return 0;
}