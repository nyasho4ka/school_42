#include <stdio.h>
#include <stdlib.h>

int is_square_fit(char** tab, int left_x, int left_y, int size, int rows, int cols)
{
    if (left_y + size > cols || left_x + size > rows)
        return 0;

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (tab[left_x + x][left_y + y] == 'o')
                return 0;
        }
    }
    return 1;
}

void ft_draw_bsq(char** tab, int rows, int cols)
{
    int curr_left_x = 0;
    int curr_left_y = 0;
    int curr_size = 0;

    int max_size = 0;
    int max_left_x = 0;
    int max_left_y = 0;

    while (1)
    {
        while (is_square_fit(tab, curr_left_x, curr_left_y, curr_size + 1, rows, cols))
            curr_size++;

        if (curr_size > max_size)
        {
            max_size = curr_size;
            max_left_x = curr_left_x;
            max_left_y = curr_left_y;
        }
        curr_left_y = curr_left_y + 1 + max_size < cols ? curr_left_y + 1 : 0;
        curr_left_x = curr_left_y == 0 ? curr_left_x + 1 : curr_left_x;
        if (curr_left_x == rows)
            break;
    }
    
    
    for (int x = max_left_x; x < max_left_x + max_size; x++)
    {
        for (int y = max_left_y; y< max_left_y + max_size; y++)
        {
            tab[x][y] = 'x';
        }
    }
}

int main()
{
    char* first = (char*)malloc(sizeof(char) * 27);
    char* first_line = "...........................";
    for (int i = 0; i < 27; i++)
    {
        first[i] = first_line[i];
    }
    char* second = (char*)malloc(sizeof(char) * 27);
    char* second_line = "....o......................";
    for (int i = 0; i < 27; i++)
    {
        second[i] = second_line[i];
    }
    char* third = (char*)malloc(sizeof(char) * 27);
    char* third_line = "............o..............";
    for (int i = 0; i < 27; i++)
    {
        third[i] = third_line[i];
    }
    char* fourth = (char*)malloc(sizeof(char) * 27);
    char* fourth_line = "...........................";
    for (int i = 0; i < 27; i++)
    {
        fourth[i] = fourth_line[i];
    }
    char* fifth = (char*)malloc(sizeof(char) * 27);
    char* fifth_line = "....o......................";
    for (int i = 0; i < 27; i++)
    {
        fifth[i] = fifth_line[i];
    }
    char* sixth = (char*)malloc(sizeof(char) * 27);
    char* sixth_line = "...............o...........";
    for (int i = 0; i < 27; i++)
    {
        sixth[i] = sixth_line[i];
    }
    char* seventh = (char*)malloc(sizeof(char) * 27);
    char* seventh_line = "...........................";
    for (int i = 0; i < 27; i++)
    {
        seventh[i] = seventh_line[i];
    }
    char* eighth = (char*)malloc(sizeof(char) * 27);
    char* eighth_line = "......o..............o.....";
    for (int i = 0; i < 27; i++)
    {
        eighth[i] = eighth_line[i];
    }
    char* ninth = (char*)malloc(sizeof(char) * 27);
    char* ninth_line = "..o.......o................";
    for (int i = 0; i < 27; i++)
    {
        ninth[i] = ninth_line[i];
    }

    char** tab = (char**)malloc(sizeof(char*) * 9);
    tab[0] = first;
    tab[1] = second;
    tab[2] = third;
    tab[3] = fourth;
    tab[4] = fifth;
    tab[5] = sixth;
    tab[6] = seventh;
    tab[7] = eighth;
    tab[8] = ninth;

    ft_draw_bsq(tab, 9, 27);

    for (int i = 0; i < 9; i++)
    {
        printf("%s\n", tab[i]);
    }
    return (0);
}