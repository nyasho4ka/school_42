#include <unistd.h>

const int ZERO_DIGIT_POSITION = 48;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_number(int number)
{
    if (number / 10 == 0)
    {
        ft_putchar('0');
        ft_putchar(number + ZERO_DIGIT_POSITION);
    }
    else
    {
        ft_putchar(number / 10 + ZERO_DIGIT_POSITION);
        ft_putchar(number % 10 + ZERO_DIGIT_POSITION);
    }
}

void ft_print_comb2(void)
{
    // Print first combination
    int i = 0;
    int j = i + 1;
    print_number(i);
    ft_putchar(' ');
    print_number(j);
    j++;
    // Print rest combinations
    for (; i < 100; i++)
    {
        j = i + 1;
        for (; j < 100; j++)
        {
            ft_putchar(',');
            ft_putchar(' ');
            print_number(i);
            ft_putchar(' ');
            print_number(j);
        }
    }
}

int main()
{
    ft_print_comb2();
    return 0;
}