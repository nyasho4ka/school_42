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

int is_char_in_base(char c, char* base, int base_len)
{
    return c >= base[0] && c <= base[base_len - 1];
}

int base_pos(char c, char* base)
{
    int i = 0;
    while (base[i] != c)
    {
        i++;
    }
    return i;
}

int ft_atoi_base(char* str, char* base)
{
    int number = 0;
    int base_len = is_base_valid(base);
    if (!base_len)
        return number;

    int i = 0;

    int start = 0;
    int is_start = 0;
    int end = 0;

    int sign = 1;
    while(str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    
    while (is_char_in_base(str[i], base, base_len))
    {
        if(!is_start)
        {
            start = i;
            is_start = 1;
        }
        i++;
    }
    end = i;

    int denominator = 1;
    for (int pos = end - 1; pos >= start; pos--)
    {
        number += base_pos(str[pos], base) * denominator;
        denominator *= base_len;
    }
    return number * sign;
}

int main()
{
    char* base = "0123456789abcdef";
    char *negative_number = "-+--+2147483zb123";
    int result = ft_atoi_base(negative_number, base);
    printf("%d\n", result);
    char *positive_number = "-+-2147483khabsd123";
    result = ft_atoi_base(positive_number, base);
    printf("%d\n", result);
    char *zero_number = "-+-0khabsd123";
    result = ft_atoi_base(zero_number, base);
    printf("%d\n", result);
    char *number = "-+-ffa12khabsd123";
    result = ft_atoi_base(number, base);
    printf("%d\n", result);

    base = "01";
    negative_number = "-+--+0012147483zb123";
    result = ft_atoi_base(negative_number, base);
    printf("%d\n", result);
    positive_number = "-+-1012147483khabsd123";
    result = ft_atoi_base(positive_number, base);
    printf("%d\n", result);
    zero_number = "-+-0khabsd123";
    result = ft_atoi_base(zero_number, base);
    printf("%d\n", result);
    number = "-+-101101khabsd123";
    result = ft_atoi_base(number, base);
    printf("%d\n", result);
    return 0;
}