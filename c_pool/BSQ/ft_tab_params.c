#include <stdlib.h>
#include "ft_tab_params.h"

int ft_atoi(char* str, int last_pos)
{
    int i = 0;

    int start = 0;
    int end = 0;
    int is_start = 0;

    int sign = 1;
    while((str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')) && i < last_pos)
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

static int ft_get_line_count_last_pos(char* line)
{
    int i = 0;
    while (line[i] >= '0' && line[i] <= '9')
        i++;
    return i;
}

t_tab_params* ft_parse_params(char* line)
{
    int digit_size = ft_get_line_count_last_pos(line);
    t_tab_params* tab_params = (t_tab_params*)malloc(sizeof(t_tab_params));
    tab_params->line_count = ft_atoi(line, digit_size);
    tab_params->empty_char = line[digit_size];
    tab_params->obstacle_char = line[digit_size+1];
    tab_params->fill_char = line[digit_size+2];
    return tab_params;
}