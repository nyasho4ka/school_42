#include <stdio.h>

int ft_iterative_power(int number, int pow)
{
    if (pow < 0)
        return 0;
    int res = 1;
    for (int i = 0; i < pow; i++)
    {
        res *= number;
    }
    return res;
}

int main()
{
    printf("%d\n", ft_iterative_power(0, 0));
    printf("%d\n", ft_iterative_power(0, 1));
    printf("%d\n", ft_iterative_power(0, 2));
    printf("%d\n", ft_iterative_power(5, 0));
    printf("%d\n", ft_iterative_power(5, -25));
    printf("%d\n", ft_iterative_power(5, 2));
    printf("%d\n", ft_iterative_power(5, 3));
    printf("%d\n", ft_iterative_power(5, 4));
    return 0;
}