#include <stdio.h>

int ft_fibonacci(int index)
{
    if (index < 0)
    {
        return -1;
    }
    if (index == 0 || index == 1)
        return index;
    return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
}

int main()
{
    printf("%d\n", ft_fibonacci(0));
    printf("%d\n", ft_fibonacci(1));
    printf("%d\n", ft_fibonacci(2));
    printf("%d\n", ft_fibonacci(3));
    printf("%d\n", ft_fibonacci(4));
    printf("%d\n", ft_fibonacci(5));
    printf("%d\n", ft_fibonacci(10));
    return 0;
}