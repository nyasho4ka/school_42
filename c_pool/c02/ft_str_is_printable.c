#include <stdio.h>
#include <stdbool.h>

const int FIRST_PRINTABLE = 32;
const int LAST_PRINTABLE = 127;

int ft_str_is_printable(char* str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) < FIRST_PRINTABLE || *(str + i) > LAST_PRINTABLE)
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char buff[6] = "1|aA/";
    int is_printable = ft_str_is_printable(buff);
    printf("is_printable %d\n", is_printable);

    char empty_buff[6] = "";
    is_printable = ft_str_is_printable(empty_buff);
    printf("is_printable %d\n", is_printable);

    char number_buff[7] = "\nell\0";
    is_printable = ft_str_is_printable(number_buff);
    printf("is_printable %d\n", is_printable);

    char only_random[10] = "\t\t\t\n\0";
    is_printable = ft_str_is_printable(only_random);
    printf("is_printable %d\n", is_printable);
}