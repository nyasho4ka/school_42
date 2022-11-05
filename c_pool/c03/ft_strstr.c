#include <stdio.h>
#include <string.h>

int is_startswith(char* str, char* to_find)
{
    int i = 0;
    while (to_find[i])
    {
        if (str[i] != to_find[i])
            return 0;
        i++;
    }
    return 1;
}

char* ft_strstr(char* str, char* to_find)
{
    int i = 0;
    while (str[i])
    {
        if (is_startswith(str + i, to_find))
            return str + i;
        i++;
    }
    return NULL;
}

int main()
{
    char *str = "hello";
    char *to_find1 = "hi";
    char *to_find2 = "ll";
    char *to_find3 = "hello, world!";

    printf("%s\n", ft_strstr(str, to_find1));
    printf("%s\n", ft_strstr(str, to_find2));
    printf("%s\n", ft_strstr(str, to_find3));
    
    return 0;
}