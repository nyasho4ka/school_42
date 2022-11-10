#include <stdlib.h>
#include <stdio.h>

int* ft_range(int min, int max)
{
    if (max < min)
        return NULL;
    
    int number_count = max - min;
    int* range = malloc(sizeof(int) * number_count);
    for (int i = 0; i < number_count; i++)
    {
        range[i] = i + min;
    }
    return range;
}

int main()
{
    int min = 50;
    int max = 100;
    int* range = ft_range(min, max);
    for (int i = 0; i < max - min; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");
    return 0;
}