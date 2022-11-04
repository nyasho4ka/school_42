#include <stdio.h>

unsigned int ft_strlcpy(char* dest, char* src, unsigned int n)
{
    unsigned int i = 0;
    dest[n - 1] = '\0';
    while (src[i])
    {
        if (i < n - 1)
            dest[i] = src[i];
        i++;
    }
    return i;
}

int main()
{
    char *str = "string example";
    unsigned int sz;
    char buf[10];

    printf("string: \"%s\"\n\n", str);
    printf("buffer before copy: \"%s\"\n", buf);

    sz = ft_strlcpy(buf, str, sizeof(buf));    
    if (sz >= sizeof(buf))      
        printf("string trim detected from %d to %lu char !\n", sz, sizeof(buf)-1);

    printf("buffer after copy:  \"%s\"\n", buf);

    return 0;
}
