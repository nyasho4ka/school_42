#include <stdio.h>

void ft_ft(int* nb)
{
    *nb = 42;
}

int main()
{
    int a = 13;
    printf("%d\n", a);
    ft_ft(&a);
    printf("%d\n", a);
}
