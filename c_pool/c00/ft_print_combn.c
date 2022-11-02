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

void ft_print_combn(int n)
{  
    int digits[n];

    for (int i = 0; i < n; i++)
    {
        digits[i] = 0;
    }

    int upper_bound = 1;
    for (int i = 0; i < n; i++)
    {
        upper_bound *= 10;
    }

    for (int i = 0; i < upper_bound; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int remainder = 10;
            for (int k = 0; k < j; k++)
            {
                remainder *= 10;
            }
            int total = remainder / 10;         
            digits[j] = i % remainder / total;
        }
        if (has_ascending_order(digits, n))
            print_number(digits, n);
    }
}

int main()
{
    ft_print_combn(3);
    return 0;
}