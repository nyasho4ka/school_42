#include <stdio.h>

int ft_recursive_power(int number, int pow)
{
    if (pow < 0)
        return 0;
    if (pow == 0)
        return 1;
    return number * ft_recursive_power(number, pow - 1);
}

int main()
{
    printf("%d\n", ft_recursive_power(0, 0));
    printf("%d\n", ft_recursive_power(0, 1));
    printf("%d\n", ft_recursive_power(0, 2));
    printf("%d\n", ft_recursive_power(5, 0));
    printf("%d\n", ft_recursive_power(5, -25));
    printf("%d\n", ft_recursive_power(5, 2));
    printf("%d\n", ft_recursive_power(5, 3));
    printf("%d\n", ft_recursive_power(5, 4));
    return 0;
}