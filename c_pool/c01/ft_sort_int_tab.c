#include <stdio.h>

void ft_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void ft_sort_int_tab(int* tab, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (tab[j] < tab[i])
            {
                ft_swap(&tab[i], &tab[j]);
            }
        }
    }
}

void print_array(int *tab, int size)
{
    if (size == 0)
    {
        printf("[]\n");
        return;
    }
    if (size == 1)
    {
        printf("[%d]\n", tab[0]);
        return;
    }
    
    printf("[%d", tab[0]);

    for (int i = 1; i < size; i++)
    {
        printf(", %d", tab[i]);
    }
    printf("]\n");
}

int main()
{
    int tab_zero[] = {};
    ft_sort_int_tab(tab_zero, 0);
    print_array(tab_zero, 0);

    int tab_one[] = {1};
    ft_sort_int_tab(tab_one, 1);
    print_array(tab_one, 1);

    int tab_two[] = {9,1};
    ft_sort_int_tab(tab_two, 2);
    print_array(tab_two, 2);

    int tab_three[] = {1, 8, 7};
    ft_sort_int_tab(tab_three, 3);
    print_array(tab_three, 3);

    int tab_random[] = {9123, 321, 321, 546, 348, 51223, 83, 1, 332234, 6754};
    ft_sort_int_tab(tab_random, 10);
    print_array(tab_random, 10);

    int tab_reverse[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    ft_sort_int_tab(tab_reverse, 9);
    print_array(tab_reverse, 9);
    return 0;
}