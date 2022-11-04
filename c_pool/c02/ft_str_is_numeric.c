#include <stdio.h>
#include <stdbool.h>

const int ZERO_DIGIT = 48;
const int NINE_DIGIT = 57;

int ft_str_is_numeric(char* str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) < ZERO_DIGIT || *(str + i) > NINE_DIGIT)
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char buff[6] = "013901";
    int is_numeric = ft_str_is_numeric(buff);
    printf("is_numeric %d\n", is_numeric);

    char empty_buff[6] = "";
    is_numeric = ft_str_is_numeric(empty_buff);
    printf("is_numeric %d\n", is_numeric);

    char number_buff[7] = "hello1";
    is_numeric = ft_str_is_numeric(number_buff);
    printf("is_numeric %d\n", is_numeric);

    char only_random[10] = "123|/asd~";
    is_numeric = ft_str_is_numeric(only_random);
    printf("is_numeric %d\n", is_numeric);
}