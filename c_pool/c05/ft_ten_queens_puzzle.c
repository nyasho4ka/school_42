#include <stdio.h>

const int N_QUEENS = 10;

int is_pos_available(int row, int column, int* busy)
{
    int success = 0;
    for (int i = 0; i < column; i++)
    {
        if (row != busy[i] && row != busy[i] + (column - i) && row != busy[i] - (column - i))
            success++;
    }
    if (success == column)
        return row;
    return -1;
}

int is_coerce(int column, int* busy)
{
    int solutions = 0;
    int rows = N_QUEENS;
    for (int row = 0; row < rows; row++)
    {
        int pos = is_pos_available(row, column, busy);
        printf("BUSY: ");
            for (int i = 0; i < rows; i++)
                printf("%d ", busy[i]);
        printf("column: %d, row: %d, is available: %d\n", column, row, pos);
        if (pos != -1)
        {
            busy[column] = pos;
            if (column == N_QUEENS - 1)
                solutions++;
            else 
                solutions += is_coerce(column + 1, busy);
        }
    }
    return solutions;
}

int ft_ten_queens_puzzle(void)
{   
    int busy[N_QUEENS] = {0};
    int res = is_coerce(0, busy);
    printf("%d\n", res);
    return res;
}

int main()
{
    ft_ten_queens_puzzle();
    return 0;
}