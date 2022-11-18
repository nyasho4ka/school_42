#include "ft_atoi.h"

int ft_atoi(char* str)
{
    int i = 0;

    int start = 0;
    int end = 0;

    int is_start = 0;

    int sign = 1;
    while(str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9'))
    {
        if (str[i] == '-')
            sign *= -1;
        else if (str[i] >= '0' && str[i] <= '9' && !is_start)
        {
            start = i;
            is_start = 1;
        }
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