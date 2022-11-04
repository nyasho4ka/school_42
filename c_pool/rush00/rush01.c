#include <stdbool.h>
#include "ft_putchar.c"

static bool is_upper_left(const int* x, const int* y)
{
    return *x == 0 && *y == 0;
}

static bool is_lower_left(const int* x, const int* y, const int* max_y)
{
    return *x == 0 && *y == *max_y;
}

static bool is_upper_right(const int* x, const int* y, const int* max_x)
{
    return *x == *max_x && *y == 0;
}

static bool is_lower_right(const int* x, const int* y, const int* max_x, const int* max_y)
{
    return *x == *max_x && *y == *max_y;
}

static bool is_vertical_edge(int x, int max_x)
{
    return x == 0 || x == max_x;
}

static bool is_horizontal_edge(int y, int max_y)
{
    return y == 0 || y == max_y;
}

void rush_1(int a, int b)
{
    int max_x = a - 1;
    int max_y = b - 1;
    for (int y = 0; y < b; y++)
    {
        for (int x = 0; x < a; x++)
        {
            if (is_upper_left(&x, &y))
                ft_putchar('/');
            else if (is_lower_left(&x, &y, &max_y))
                ft_putchar('\\');
            else if (is_upper_right(&x, &y, &max_x))
                ft_putchar('\\');
            else if (is_lower_right(&x, &y, &max_x, &max_y))
                ft_putchar('/');
            else if (is_horizontal_edge(y, max_y) || is_vertical_edge(x, max_x))
                ft_putchar('*');
            else
                ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}