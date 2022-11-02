#include <unistd.h>
#include <stdbool.h>

const int ZERO_DIGIT_POSITION = 48;
const int MAX_INT_DIGITS = 10;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_digit(int digit)
{
    ft_putchar(digit + ZERO_DIGIT_POSITION);
}

void ft_putnbr(int nb)
{
    int digit_count = 1;
    int denominator = 10;
    while(nb / denominator != 0)
    {
        digit_count++;
        denominator *= 10;
        if (digit_count == MAX_INT_DIGITS)
        {
            break;
        }
    }

    if (nb < 0)
    {
        nb *= -1;
        ft_putchar('-');
    }

    for (int i = digit_count - 1; i > 0; i--)
    {
        int denominator = 1;
        for (int j = 1; j <= i; j++)
        {
            denominator *= 10;
        }
        print_digit(nb / denominator);
        nb = nb % denominator;
    }
    print_digit(nb);
}

int main()
{
    ft_putnbr(42);
    ft_putchar('\n');
    ft_putnbr(-1);
    ft_putchar('\n');
    ft_putnbr(100);
    ft_putchar('\n');
    ft_putnbr(0);
    ft_putchar('\n');
    ft_putnbr(-121321);
    ft_putchar('\n');
    ft_putnbr(8965);
    ft_putchar('\n');
    ft_putnbr(2147483647);
    ft_putchar('\n');
}