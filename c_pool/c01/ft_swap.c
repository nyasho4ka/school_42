#include <stdio.h>

void ft_swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int a = 42;
    int b = 21;
    printf("a: %d, b: %d\n", a, b);
    ft_swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    return 0;
}