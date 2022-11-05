#include <stdio.h>

char* ft_strcat(char *dest, char *src)
{
    // seek dest end
    int i = 0;
    while (dest[i])
    {
        i++;
    }

    // append src to dest
    int j = 0;
    while (src[j])
    {
        dest[i + j] = src[j];
        j++;
    }

    dest[i+j] = '\0';
    return dest;
}

int main()
{
    char dest_str[32] = "hello";
    char *src_str = ", world!";
    printf("%s\n", dest_str);
    ft_strcat(dest_str, src_str);
    printf("%s\n", dest_str);
    return 0;
}