#include <stdio.h>

int ft_is_empty(char* str)
{
    int i = 0;
    while (str[i])
        i++;
    return !i;
}

int ft_count_if(char** tab, int length, int(*f)(char*))
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if ((*f)(tab[i]))
            count++;
    }
    return count;
}

int main()
{
    char* tab[10];
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            tab[i] = "";
        else
            tab[i] = "hello";
    }
    printf("ft_count_if: %d\n", ft_count_if(tab, 10, ft_is_empty));
    return (0);
}