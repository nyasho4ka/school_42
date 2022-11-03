#include <stdio.h>

void ft_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

}

void ft_rev_int_tab(int *tab, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        ft_swap(&tab[i], &tab[size - i - 1]);
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
    printf("TAB EVEN: \n");
    int tab_even[] = {1, 2, 3, 4};
    print_array(tab_even, 4);
    ft_rev_int_tab(tab_even, 4);
    print_array(tab_even, 4);
    printf("\n");

    printf("TAB ODD: \n");
    int tab_odd[] = {1, 9, 4, 5, 2};
    print_array(tab_odd, 5);
    ft_rev_int_tab(tab_odd, 5);
    print_array(tab_odd, 5);
    printf("\n");

    printf("TAB EMPTY: \n");
    int tab_empty[] = {};
    print_array(tab_empty, 0);
    ft_rev_int_tab(tab_empty, 0);
    print_array(tab_empty, 0);
    printf("\n");

    printf("TAB ONE: \n");
    int tab_one[] = {9};
    print_array(tab_one, 1);
    ft_rev_int_tab(tab_one, 1);
    print_array(tab_one, 1);
    printf("\n");

    printf("TAB TWO: \n");
    int tab_two[] = {9, 8};
    print_array(tab_two, 2);
    ft_rev_int_tab(tab_two, 2);
    print_array(tab_two, 2);
    printf("\n");

    return 0;
}