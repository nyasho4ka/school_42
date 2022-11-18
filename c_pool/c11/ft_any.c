#include <stdio.h>

int ft_is_empty(char* str)
{
    int i = 0;
    while (str[i])
        i++;
    return !i;
}

int ft_any(char** tab, int(*f)(char*))
{
    while (*tab)
    {
        if ((*f)(*tab++))
            return (1);
    }
    return (0);
}

int main()
{
    char* tab[3];
    tab[0] = "hello";
    tab[1] = "";
    tab[2] = NULL;
    if (ft_any(tab, &ft_is_empty))
        printf("IS ANY EMPTY!\n");

    char* test_tab[5];
    test_tab[0] = "non empty";
    test_tab[1] = "too";
    test_tab[2] = "heh";
    test_tab[3] = "nope";
    test_tab[4] = NULL;
    if (ft_any(test_tab, &ft_is_empty))
        printf("IS ANY EMPTY!\n");
    else
        printf("ALL IS NON EMPTY!\n");
    return (0);
}