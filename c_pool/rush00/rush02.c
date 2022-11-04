// Another approach
#include "ft_putchar.c"

void ft_print_line(int max_x, char begin_char, char middle_char, char end_char)
{
    for (int x = 0; x <= max_x; x++)
    {
        if (x == 0)
            ft_putchar(begin_char);
        else if (x == max_x)
            ft_putchar(end_char);
        else
            ft_putchar(middle_char);
    }
    ft_putchar('\n');
}

void rush_2(int a, int b)
{
    int max_x = a - 1;
    int max_y = b - 1;
    for (int y = 0; y <= max_y; y++)
    {
        if (y == 0)
            ft_print_line(max_x, 'A', 'B', 'A');
        else if (y == max_y)
            ft_print_line(max_x, 'C', 'B', 'C');
        else
            ft_print_line(max_x, 'B', ' ', 'B');
    }
}