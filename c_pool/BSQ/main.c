#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_fstream.h"
#include "ft_tab_params.h"

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

int main(int argc, char** argv)
{
    if (argc == 1)
        return (0);

    char* file_name = argv[1];
    int fd = open(file_name, O_RDONLY);
    t_fstream* stream = create_fstream(fd);
    int status = 0;
    t_tab_params* tab_params = ft_parse_params(ft_getline(stream, &status));
    printf("line_count: %d, empty_char: %c, obstacle_char: %c, fill_char: %c\n", 
        tab_params->line_count, tab_params->empty_char, tab_params->obstacle_char, tab_params->fill_char);
    
    char** tab = (char**)malloc(sizeof(char*) * tab_params->line_count);
    for (int i = 0; i < tab_params->line_count; i++)
    {
        tab[i] = ft_getline(stream, &status);
        if (status == -1 && i < tab_params->line_count - 1)
            break;
    }

    for (int i = 0; i < 9; i++)
    {
        printf("%s\n", tab[i]);
    }
    printf("---------------------------\n");
    ft_draw_bsq(tab, 9, 27);

    for (int i = 0; i < 9; i++)
    {
        printf("%s\n", tab[i]);
    }
    return (0);
}