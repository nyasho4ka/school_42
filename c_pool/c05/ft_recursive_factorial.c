#include <stdio.h>

int ft_recursive_factorial(int number)
{
    if (number == 1)
        return number;
    return number * ft_recursive_factorial(number - 1);
}

int main()
{
    printf("%d\n", ft_recursive_factorial(1));
    printf("%d\n", ft_recursive_factorial(2));
    printf("%d\n", ft_recursive_factorial(3));
    printf("%d\n", ft_recursive_factorial(4));
    printf("%d\n", ft_recursive_factorial(12));
    return 0;
}