#include <stdio.h>
#include <string.h>

int ft_strncmp(const char* s1, const char* s2, unsigned int size)
{
    unsigned int i = 0;
    while (s1[i] && (s1[i] == s2[i]) && i + 1 < size)
    {
        i++;
    }
    return s1[i] - s2[i];
}

int main()
{
    char *s1 = "hello";
    char *s2 = "helloo";
    for (unsigned int i = 0; i < 8; i++)
    {
        printf("%d\n", ft_strncmp(s1, s2, i));
        printf("%d\n", strncmp(s1, s2, i));
        printf("-----------\n");
    }
    return 0;
}