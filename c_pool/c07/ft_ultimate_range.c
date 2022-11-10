#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int** range, int min, int max)
{
    if (max < min)
    {
        range = NULL;
        return 0;    
    }

    int number_count = max - min;
    int *int_range = malloc(sizeof(int) * number_count);

    if (int_range == NULL)
        return -1;

    for (int i = 0; i < number_count; i++)
    {
        int_range[i] = i + min;
    }

    *range = int_range;
    return number_count;
}

int main()
{
    int* range = NULL;
    int** ult_range = &range;
    int range_size = ft_ultimate_range(ult_range, 50, 100);
    for (int i = 0; i < range_size; i++)
    {
        printf("%d ", ult_range[0][i]);
    }
    printf("\n");
    return 0;
}