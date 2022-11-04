#include <stdio.h>

const int CASE_DIFF = 'a' - 'A';

char* ft_strlowcase(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        if (*(str + i) >= 'A' && *(str + i) <= 'Z')
            *(str + i) += CASE_DIFF;
        i++;
    }
    return str;
}

int main()
{
    printf("NON EMPTY\n");
    char str[13] = {"SOM ESTRING\n"};
    printf("%s", str);
    ft_strlowcase(str);
    printf("%s", str);

    printf("EMPTY\n");
    char empty_str[12] = {"\n"};
    printf("%s", empty_str);
    ft_strlowcase(empty_str);
    printf("%s", empty_str);
    
    printf("MIXED\n");
    char mixed_str[12] = {"S1B23LOLha\n"};
    printf("%s", mixed_str);
    ft_strlowcase(mixed_str);
    printf("%s", mixed_str);
    return 0;
}