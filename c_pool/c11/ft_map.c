#include <stdio.h>
#include <stdlib.h>

int square(int i)
{
    return i * i;
}

int* ft_map(int* tab, int length, int(*f)(int))
{
    int* new_tab = (int*)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        new_tab[i] = (*f)(tab[i]);
    }
    return new_tab;
}

int main()
{   
    int tab[6] = {1, -2, 3, -4, 625, -99};
    int *map_tab = ft_map(tab, 6, &square);
    for (int i = 0; i < 6; i++)
    {
        printf("map_tab[%d]: %d\n", i, map_tab[i]);
    }
    return (0);
}