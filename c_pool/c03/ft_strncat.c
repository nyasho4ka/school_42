#include <stdio.h>
#include <string.h>

char* ft_strncat(char *dest, char *src, unsigned int size)
{
    // seek dest end
    int i = 0;
    while (dest[i])
    {
        i++;
    }

    // append src to dest
    unsigned int j = 0;
    while (src[j] && j < size)
    {
        dest[i + j] = src[j];
        j++;
    }

    dest[i+j] = '\0';
    return dest;
}

int main()
{
    char dest_str[10] = "hello";
    char *src_str = ", world!";
    printf("%s\n", dest_str);
    ft_strncat(dest_str, src_str, sizeof(dest_str) - strlen(dest_str) - 1);
    printf("%s\n", dest_str);
    
    return 0;
}