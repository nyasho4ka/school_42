#include <stdio.h>

int ft_sqrt(int number)
{    
    int i = 0;
    while (i * i < number)
        i++;
    if (i * i == number)
        return i;
    return 0;
}

int main()
{
    printf("%d\n", ft_sqrt(0));
    printf("%d\n", ft_sqrt(1));
    printf("%d\n", ft_sqrt(2));
    printf("%d\n", ft_sqrt(4));
    printf("%d\n", ft_sqrt(7));
    printf("%d\n", ft_sqrt(9));
    printf("%d\n", ft_sqrt(13));
    printf("%d\n", ft_sqrt(16));
    return 0;
}