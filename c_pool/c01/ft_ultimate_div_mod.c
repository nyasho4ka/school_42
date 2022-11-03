#include <stdio.h>

void ft_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void ft_ultimate_div_mod(int *a, int *b)
{
    *b = *a / *b;
    *a = *a % (*a / *b);
    ft_swap(a, b);
}

int main()
{
    int a = 81283;
    int b = 37;
    printf("a: %d, b: %d, ", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("div: %d, mod: %d\n", a, b);
}