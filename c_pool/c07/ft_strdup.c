#include <stdlib.h>
#include <stdio.h>

char* ft_strdup(char *str)
{
    int char_count = 0;
    while (str[char_count])
    {
        char_count++;
    }
    char* str_copy = malloc(sizeof(str));

    if (str_copy == NULL)
        return str_copy;

    for (int i = 0; i <= char_count; i++)
    {
        str_copy[i] = str[i];
    }
    return str_copy;
}

int main()
{
    char *str = "hello";
    char *str_copy = ft_strdup(str);
    printf("%s\n", str_copy);
    return 0;
}