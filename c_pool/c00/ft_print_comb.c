#include <unistd.h>
#include <stdbool.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_number(int* digits, int length)
{
    for (int i = length - 1; i >= 0; i--)
    {
        ft_putchar(digits[i] + 48);
    }   
    ft_putchar('\n');
}

bool has_ascending_order(int* digits, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (digits[i] <= digits[i + 1])
            return false;
    }
    return true;
}

void ft_print_comb(void)
{  
    int digits[3];

    for (int i = 0; i < 3; i++)
    {
        digits[i] = 0;
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int remainder = 10;
            for (int k = 0; k < j; k++)
            {
                remainder *= 10;
            }
            int total = remainder / 10;         
            digits[j] = i % remainder / total;
        }
        if (has_ascending_order(digits, 3))
            print_number(digits, 3);
    }
}

int main()
{
    ft_print_comb();
    return 0;
}