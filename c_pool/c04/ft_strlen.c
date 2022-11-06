#include <stdio.h>

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

int main()
{
    char *empty_string = "";
    printf("empty_string len: %d\n", ft_strlen(empty_string));
    char *one_char_string = "a";
    printf("one_char_string len: %d\n", ft_strlen(one_char_string));
    char *long_string = "oub12uv3asd";
    printf("long_string len: %d\n", ft_strlen(long_string));
    return 0;
}