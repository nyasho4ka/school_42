#include <stdio.h>

const int CASE_DIFF = 'a' - 'A';

char* ft_strupcase(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) >= 'a' && *(str + i) <= 'z')
            *(str + i) -= CASE_DIFF;
        i++;
    }
    return str;
}

int main()
{
    printf("NON EMPTY\n");
    char str[13] = {"som estring\n"};
    printf("%s", str);
    ft_strupcase(str);
    printf("%s", str);

    printf("EMPTY\n");
    char empty_str[12] = {"\n"};
    printf("%s", empty_str);
    ft_strupcase(empty_str);
    printf("%s", empty_str);
    
    printf("MIXED\n");
    char mixed_str[12] = {"s1b23lolHA\n"};
    printf("%s", mixed_str);
    ft_strupcase(mixed_str);
    printf("%s", mixed_str);
    return 0;
}