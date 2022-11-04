#include <stdio.h>
#include <stdbool.h>

const int ALPHA_UPPER = 65;
const int ZULU_UPPER = 90;

int ft_str_is_uppercase(char* str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) < ALPHA_UPPER || *(str + i) > ZULU_UPPER)
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char buff[6] = "HELLO";
    int is_uppercase = ft_str_is_uppercase(buff);
    printf("is_uppercase %d\n", is_uppercase);

    char empty_buff[6] = "";
    is_uppercase = ft_str_is_uppercase(empty_buff);
    printf("is_uppercase %d\n", is_uppercase);

    char number_buff[7] = "Hello";
    is_uppercase = ft_str_is_uppercase(number_buff);
    printf("is_uppercase %d\n", is_uppercase);

    char only_random[10] = "123|/asd~";
    is_uppercase = ft_str_is_uppercase(only_random);
    printf("is_uppercase %d\n", is_uppercase);
}