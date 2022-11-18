#include <stdio.h>

int ft_strcmp(char* s1, char* s2)
{
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s1[i] - s2[i];
}

int ft_strcmp_reverse(char* s1, char* s2)
{
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s2[i] - s1[i];
}

void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char* str1, char* str2))
{
    int i = 0;
    int j = 0;
    char* temp;
    while (tab[i + 1])
    {
        j = i + 1;
        while(tab[j])
        {
            if ((*cmp)(tab[j], tab[i]) < 0)
            {       
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int main()
{
    char* strings[10];
    strings[0] = "hello";
    strings[1] = "world";
    strings[2] = "how are you?";
    strings[3] = "I am fine";
    strings[4] = "zero number";
    strings[5] = "last string?";
    strings[6] = "don't think so";
    strings[7] = "hahaha";
    strings[8] = "random string";
    strings[9] = (void*)(0);
    printf("BEFORE SORTING:\n");
    for (int i = 0; i < 10; i++)
        printf("i: %d, string: %s\n", i, strings[i]);
    ft_advanced_sort_string_tab(strings, ft_strcmp);
    printf("AFTER SORTING:\n");
    for (int i = 0; i < 10; i++)
        printf("i: %d, string: %s\n", i, strings[i]);
    printf("\n");
    strings[0] = "hello";
    strings[1] = "world";
    strings[2] = "how are you?";
    strings[3] = "I am fine";
    strings[4] = "zero number";
    strings[5] = "last string?";
    strings[6] = "don't think so";
    strings[7] = "hahaha";
    strings[8] = "random string";
    strings[9] = (void*)(0);
    printf("BEFORE SORTING:\n");
    for (int i = 0; i < 10; i++)
        printf("i: %d, string: %s\n", i, strings[i]);
    ft_advanced_sort_string_tab(strings, ft_strcmp_reverse);
    printf("AFTER SORTING:\n");
    for (int i = 0; i < 10; i++)
        printf("i: %d, string: %s\n", i, strings[i]);
    return (0);
}