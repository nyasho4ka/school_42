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

int main()
{
    printf("number: %d, is_prime: %d\n", 0, is_prime(0));
    printf("number: %d, is_prime: %d\n", 1, is_prime(1));
    printf("number: %d, is_prime: %d\n", 2, is_prime(2));
    printf("number: %d, is_prime: %d\n", 3, is_prime(3));
    printf("number: %d, is_prime: %d\n", 4, is_prime(4));
    printf("number: %d, is_prime: %d\n", 37, is_prime(37));
    printf("number: %d, is_prime: %d\n", 111, is_prime(111));
}