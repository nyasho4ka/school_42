#include <stdio.h>

int is_prime(int number)
{
    if (number == 0 || number == 1)
        return 0;

    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int ft_find_next_prime(int number)
{
    while (!is_prime(number))
    {
        number++;
    }
    return number;
}

int main()
{
    printf("ft_find_next_prime(0): %d\n", ft_find_next_prime(0));
    printf("ft_find_next_prime(1): %d\n", ft_find_next_prime(1));
    printf("ft_find_next_prime(2): %d\n", ft_find_next_prime(2));
    printf("ft_find_next_prime(4): %d\n", ft_find_next_prime(4));
    printf("ft_find_next_prime(111): %d\n", ft_find_next_prime(111));
}