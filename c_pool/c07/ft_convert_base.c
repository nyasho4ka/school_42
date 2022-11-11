#include <stdlib.h>
#include <stdio.h>

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

int is_char_in_base_from(char c, char* base_from, int base_from_size)
{
    return c >= base_from[0] && c <= base_from[base_from_size - 1];
}

int base_pos(char digit, char *base)
{
    int i = 0;
    while (base[i] != digit)
    {
        i++;
    }
    return i;
}

int ft_atoi_base(char *nbr, char *base, int base_size)
{
    // check number sign
    int i = 0;
    int sign = 1;
    while (nbr[i] == '-' || nbr[i] == '+' || nbr[i] == ' ')
    {
        if (nbr[i] == '-')
            sign *= -1;
    }

    // find range of number
    int start = 0;
    int end = 0;
    int is_start = 0;
    while (is_char_in_base_from(nbr[i], base, base_size))
    {
        if (!is_start)
        {
            is_start = 1;
            start = i;
        }
        i++;
    }
    end = i;

    int number = 0;
    int denominator = 1;
    for (int pos = end - 1; pos >= start; pos--)
    {
        number += base_pos(nbr[pos], base) * denominator;
        denominator *= base_size;
    }
    return number * sign;
}

char* ft_itoa_base(int number, char* base, int base_size)
{
    int digit_number = 1;
    int denominator = 1;
    while (number / denominator > base_size - 1)
    {
        digit_number++;
        denominator *= base_size;
    }
    int char_count = number < 0 ? digit_number + 2 : digit_number + 1;  // include \0 char
    char* base_to_number = malloc(sizeof(char) * char_count);
    int i = 0;
    if (number < 0)
    {
        base_to_number[i] = '-';
        i++;
    }
    while (denominator)
    {
        base_to_number[i] = base[number / denominator];
        number = number % denominator;
        denominator /= base_size;
        i++;
    }
    base_to_number[i] = '\0';

    return base_to_number;
}

char* ft_convert_base(char* nbr, char* base_from, char* base_to)
{
    int base_from_size = is_base_valid(base_from);
    int base_to_size = is_base_valid(base_to);

    if (!base_from_size || !base_to_size)
        return NULL;
    
    int dec_number = ft_atoi_base(nbr, base_from, base_from_size);
    char* base_to_number = ft_itoa_base(dec_number, base_to, base_to_size);
    return base_to_number;
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        char* number = argv[1];
        char* base_from = argv[2];
        char* base_to = argv[3];
        char* result = ft_convert_base(number, base_from, base_to);
        printf("%s\n", result);
    }
}