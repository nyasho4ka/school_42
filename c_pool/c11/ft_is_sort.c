#include <stdio.h>

int ft_compare(int i1, int i2)
{
    return i1 - i2;
}

int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    for (int i = 0; i < length - 1; i++)
    {
        if ((*f)(tab[i + 1], tab[i]) < 0)
        {
            return (0);
        }
    }
    return (1);
}

int main()
{
    int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("tab ft_is_sort: %d\n", ft_is_sort(tab, 10, ft_compare));
    int test_tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("test_tab ft_is_sort: %d\n", ft_is_sort(test_tab, 10, ft_compare));
    return (0);
}