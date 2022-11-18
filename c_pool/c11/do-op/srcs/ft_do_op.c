#include <stdio.h>
#include "ft_do_op.h"

void ft_init_op()
{
    operators[0].op_char = '+';
    operators[0].f = &ft_sum;

    operators[1].op_char = '-';
    operators[1].f = &ft_sub;

    operators[2].op_char = '*';
    operators[2].f = &ft_mul;

    operators[3].op_char = '/';
    operators[3].f = &ft_div;
    
    operators[4].op_char = '%';
    operators[4].f = &ft_mod;
}

void ft_sum(int first, int second)
{
    printf("%d\n", first + second);
}

void ft_sub(int first, int second)
{
    printf("%d\n", first - second);
}

void ft_mul(int first, int second)
{
    printf("%d\n", first * second);
}

void ft_div(int first, int second)
{
    if (second == 0)
    {
        printf("Stop: division by zero\n");
    }
    else
    {
        printf("%d\n", first / second);
    }
}

void ft_mod(int first, int second)
{
    if (second == 0)
    {
        printf("Stop: modulo by zero\n");
    }
    else
    {
        printf("%d\n", first % second);
    }
}


void ft_do_op(int first, char op, int second)
{
    for (int i = 0; i < 5; i++)
    {
        if (operators[i].op_char == op)
        {
            (*operators[i].f)(first, second);
            break;
        }
    }
}