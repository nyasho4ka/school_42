#include <stdio.h>
#include <stdlib.h>

int is_left_available(int checked_value, int row, int column, int** puzzle)
{
    int left_value = puzzle[row][0];
    int already_seen = 1;
    
    int compared_value = puzzle[row][1];
    for (int i = 1; i < column; i++)
    {
        if (i == column - 1)
        {
            if (compared_value < checked_value)
                already_seen++;
        }
        else if (compared_value < puzzle[row][i + 1])
        {
            already_seen++;
            compared_value = puzzle[row][i + 1];
        }
    }
    if (already_seen <= left_value)
    {
        return 1;
    }
    return 0;
}

int is_up_available(int checked_value, int row, int column, int** puzzle)
{
    int up_value = puzzle[0][column];
    int already_seen = 1;
    
    int compared_value = puzzle[1][column];
    for (int i = 1; i < row; i++)
    {
        if (i == row - 1)
        {
            if (compared_value < checked_value)
                already_seen++;
        }
        else if (compared_value < puzzle[i+1][column])
        {
            already_seen++;
            compared_value = puzzle[i + 1][column];
        }
    }
    if (already_seen <= up_value)
    {
        return 1;
    }

    return 0;
}

int is_right_available(int checked_value, int row, int column, int** puzzle)
{
    int right_value = puzzle[row][5];
    int reversed_column = 4 - column + 1;
    
    // check unaccessible position for 4
    if (checked_value == 4 && reversed_column - right_value < 0)
        return 0;
    
    // count buildings after fill a row
    if (column != 4)
        return 1;

    int building_count = 1; // because of checked value
    int compared_value = checked_value;
    for (int i = 3; i >= 1; i--)
    {
        if (compared_value < puzzle[row][i])
        {
            building_count++;
            compared_value = puzzle[row][i];
        }
    }
    if (building_count == right_value)
        return 1;
    
    return 0;
}

int is_down_available(int checked_value, int row, int column, int** puzzle)
{
    int down_value = puzzle[5][column];
    int reversed_column = 4 - row + 1;

    if (checked_value == 4 && reversed_column - down_value < 0)
        return 0;

    if (row != 4)
        return 1;

    int building_count = 1; // because of checked value
    int compared_value = checked_value;
    for (int i = 3; i >= 1; i--)
    {
        if (compared_value < puzzle[i][column])
        {
            building_count++;
            compared_value = puzzle[i][column];
        }
    }
    if (building_count == down_value)
        return 1;

    return 0;
}

int get_value(int checked_value, int row, int column, int** puzzle)
{
    // Check if it is not reserved value in a row
    for (int i = 1; i < column; i++)
    {
        if (checked_value == puzzle[row][i])
            return -1;
    }

    // Check if it is not reserved value in a column
    for (int i = 1; i < row; i++)
    {
        if (checked_value == puzzle[i][column])
            return -1;
    }

    int is_left = is_left_available(checked_value, row, column, puzzle);
    int is_right = is_right_available(checked_value, row, column, puzzle);
    int is_up = is_up_available(checked_value, row, column, puzzle);
    int is_down = is_down_available(checked_value, row, column, puzzle);
    if (!is_left || !is_right || !is_up || !is_down)
        return -1;
    
    return checked_value;
}

int is_solved(int row, int column, int** puzzle)
{
    int success = 0;
    for (int i = 1; i <= 4; i++)
    {
        int value = get_value(i, row, column, puzzle);
        if (value != -1)
        {
            puzzle[row][column] = i;
            if (row == 4 && column == 4)
            {
                success = 1;
                break;
            }

            if (column == 4)
            {
                success = is_solved(row + 1, 1, puzzle);
            }
            else
            {
                success = is_solved(row, column + 1, puzzle);
            }

            if (success)
                break;
        }
    }
    return success;
}

void ft_fill_board(int** puzzle)
{
    puzzle[0][1] = 3;
    puzzle[0][2] = 2;
    puzzle[0][3] = 1;
    puzzle[0][4] = 3;

    puzzle[5][1] = 1;
    puzzle[5][2] = 3;
    puzzle[5][3] = 3;
    puzzle[5][4] = 2;

    puzzle[1][0] = 3;
    puzzle[2][0] = 2;
    puzzle[3][0] = 4;
    puzzle[4][0] = 1;

    puzzle[1][5] = 2;
    puzzle[2][5] = 2;
    puzzle[3][5] = 1;
    puzzle[4][5] = 2;
}

void ft_solve_puzzle(int** puzzle)
{
    int success = is_solved(1, 1, puzzle);
    printf("SUCCESS: %d\n", success);
}

int main()
{
    int **puzzle;
    puzzle = malloc(6 * sizeof *puzzle);
    for (int i=0; i<6; i++)
    {
        puzzle[i] = malloc(6 * sizeof *puzzle[i]);
    }

    ft_fill_board(puzzle);
    ft_solve_puzzle(puzzle);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}