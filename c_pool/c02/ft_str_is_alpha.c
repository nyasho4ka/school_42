#include <stdio.h>
#include <stdbool.h>

const int ALPHA_UPPER = 65;
const int ZULU_UPPER = 90;

const int ALPHA_LOWER = 97;
const int ZULU_LOWER = 122;

bool is_lower_alphabet(const char *c)
{
    return *c >= ALPHA_LOWER && *c <= ZULU_LOWER;
}

bool is_upper_alphabet(const char *c)
{
    return *c >= ALPHA_UPPER && *c <= ZULU_UPPER;
}

int ft_str_is_alpha(char* str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (!is_lower_alphabet(str + i) && !is_upper_alphabet(str + i))
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char buff[6] = "hello";
    int is_alpha = ft_str_is_alpha(buff);
    printf("is_alpha %d\n", is_alpha);

    char empty_buff[6] = "";
    is_alpha = ft_str_is_alpha(empty_buff);
    printf("is_alpha %d\n", is_alpha);

    char number_buff[7] = "hello1";
    is_alpha = ft_str_is_alpha(number_buff);
    printf("is_alpha %d\n", is_alpha);

    char only_random[10] = "123|/asd~";
    is_alpha = ft_str_is_alpha(only_random);
    printf("is_alpha %d\n", is_alpha);
}