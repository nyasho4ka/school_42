#include <stdio.h>
#include <string.h>

int ft_strcmp(const char* s1, const char* s2)
{
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s1[i] - s2[i];
}

int main()
{
    char *s1 = "hello";
    char *s2 = "helloo";
    printf("%d\n", ft_strcmp(s1, s2));
    printf("%d\n", strcmp(s1, s2));
    return 0;
}