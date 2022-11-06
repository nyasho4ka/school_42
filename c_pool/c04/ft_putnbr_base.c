#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int is_twiced(int i, char* base)
{
    int j = i + 1;
    while (base[j])
    {
        if (base[i] >= base[j])
            return 1;
        j++;
    }
    return 0;
}

int is_base_valid(char* base)
{
    unsigned int i = 0;
    while (base[i])
    {
        if (!is_alpha(base[i]))  // if not alpha -> base failed
            return 0;
        if (is_twiced(i, base))  // if is twiced -> base failed
            return 0;
        i++;
    }

    if (i <= 1)
        return 0;
    return i;
}

void ft_putnbr_base(int nbr, char* base)
{
    int base_len = is_base_valid(base);
    if (!base_len)
        return;
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr *= -1;
    }
    
    int digit_number = 1;
    int denominator = 1;

    while (nbr / denominator > base_len - 1)
    {
        digit_number++;
        denominator *= base_len;
    }

    printf("DIGIT_NUMBER: %d\n", digit_number);
    printf("DENOMINATOR: %d\n", denominator);

    while (denominator)
    {
        ft_putchar(base[nbr / denominator]);
        nbr = nbr % denominator;
        denominator /= base_len;
    }
}

int main()
{
    char* hex = "0123456789abcdef";
    ft_putnbr_base(-2147483647, hex);
    ft_putchar('\n');
    return 0;
}