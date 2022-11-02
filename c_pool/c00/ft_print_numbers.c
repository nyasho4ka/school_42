#include <unistd.h>


void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_numbers(void)
{
    char current_digit = '0';
    do
    {
        ft_putchar(current_digit);
        current_digit++;
    } while (current_digit <= '9');
    
}

int main()
{
    ft_print_numbers();
    return 0;
}