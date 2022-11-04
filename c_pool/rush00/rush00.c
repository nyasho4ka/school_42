#include <stdbool.h>
#include "ft_putchar.c"

bool is_corner(int x, int y, int max_x, int max_y)
{
    return (x == 0 && y == 0) || (x == 0 && y == max_y) || (x == max_x && y == 0) || (x == max_x && y == max_y);
}

bool is_vertical_edge(int x, int max_x)
{
    return x == 0 || x == max_x;
}

bool is_horizontal_edge(int y, int max_y)
{
    return y == 0 || y == max_y;
}

void rush_0(int a, int b)
{
    int max_x = a - 1;
    int max_y = b - 1;
    for (int y = 0; y < b; y++)
    {
        for (int x = 0; x < a; x++)
        {
            if (is_corner(x, y, max_x, max_y))
                ft_putchar('o');
            else if (is_horizontal_edge(y, max_y))
                ft_putchar('-');
            else if (is_vertical_edge(x, max_x))
                ft_putchar('|');
            else
                ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}