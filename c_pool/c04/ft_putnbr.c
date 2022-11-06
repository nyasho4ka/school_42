#include <unistd.h>
#include <stdio.h>

const int MAX_DIGITS = 10;
const int ZERO_DIGIT = 48;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    if (nbr < 0)
    {
        ft_putchar('-');
        if (nbr == -2147483648)
        {
            ft_putchar('2');
            nbr = -147483648;
        }
        nbr *= -1;
    }

    int digit_number = 1;
    int denominator = 1;

    while (nbr / denominator > 9)
    {
        digit_number++;
        denominator *= 10;
    }

    while (denominator)
    {
        ft_putchar(nbr / denominator + ZERO_DIGIT);
        nbr = nbr % denominator;
        denominator /= 10;
    }
    
}

int main()
{
    ft_putnbr(-2147483648);
    ft_putchar('\n');
    ft_putnbr(-2147483647);
    ft_putchar('\n');
    ft_putnbr(2147483647);
    ft_putchar('\n');
    return 0;
}