#include <stdio.h>

int ft_atoi(char* str)
{
    int i = 0;

    int start = 0;
    int end = 0;

    int sign = 1;
    while(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9'))
    {
        if (str[i] == '-')
            sign *= -1;
        else if (str[i] >= '0' && str[i] <= '9' && !start)
            start = i;
        i++;
    }
    end = i;

    int number = 0;
    int denominator = 1;
    for (int pos = end - 1; pos >= start; pos--)
    {
        number += (str[pos] - 48) * denominator;
        denominator *= 10;
    }
    return number * sign;
}

int main()
{
    char *negative_number = "-+--+2147483648fb123";
    int result = ft_atoi(negative_number);
    printf("%d\n", result);
    char *positive_number = "-+-2147483647khabsd123";
    result = ft_atoi(positive_number);
    printf("%d\n", result);
    char *zero_number = "-+-0khabsd123";
    result = ft_atoi(zero_number);
    printf("%d\n", result);
    char *no_number = "-+-khabsd123";
    result = ft_atoi(no_number);
    printf("%d\n", result);
    return 0;
}