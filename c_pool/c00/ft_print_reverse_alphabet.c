#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_alphabet(void)
{
    char first_letter = 97;
    char last_letter = first_letter + 25;
    for (char letter = last_letter; letter >= first_letter; letter--)
    {
        ft_putchar(letter);
    }
}

int main()
{
    ft_print_alphabet();
}