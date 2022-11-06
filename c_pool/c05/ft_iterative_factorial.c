#include <stdio.h>

int ft_iterative_factorial(int number)
{
    int res = 1;
    for (int i = 2; i <= number; i++)
    {
        res *= i;
    }
    return res;
}

int main()
{
    printf("%d\n", ft_iterative_factorial(1));
    printf("%d\n", ft_iterative_factorial(2));
    printf("%d\n", ft_iterative_factorial(3));
    printf("%d\n", ft_iterative_factorial(4));
    printf("%d\n", ft_iterative_factorial(12));
    return 0;
}