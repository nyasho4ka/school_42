#include <stdio.h>
#include <stdbool.h>

const int ALPHA_LOWER = 97;
const int ZULU_LOWER = 122;

int ft_str_is_lowercase(char* str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) < ALPHA_LOWER || *(str + i) > ZULU_LOWER)
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char buff[6] = "asdnl";
    int is_lowercase = ft_str_is_lowercase(buff);
    printf("is_lowercase %d\n", is_lowercase);

    char empty_buff[6] = "";
    is_lowercase = ft_str_is_lowercase(empty_buff);
    printf("is_lowercase %d\n", is_lowercase);

    char number_buff[7] = "Hello";
    is_lowercase = ft_str_is_lowercase(number_buff);
    printf("is_lowercase %d\n", is_lowercase);

    char only_random[10] = "123|/asd~";
    is_lowercase = ft_str_is_lowercase(only_random);
    printf("is_lowercase %d\n", is_lowercase);
}