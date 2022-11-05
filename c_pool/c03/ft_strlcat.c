#include <stdio.h>

unsigned int ft_strlcat(char* dest, char* src, unsigned int size)
{
    // seek dest end
    unsigned int i = 0;
    while (dest[i])
    {
        i++;
    }

    // append src to dest
    unsigned int j = 0;
    while (src[j] && i + j < size - 1)
    {
        dest[i + j] = src[j];
        j++;
    }

    dest[i+j] = '\0';

    while (src[j])
    {
        j++;
    }
    j++;
    return i + j;
}

int main()
{
    char dest_str[7] = "hello";
    char *src_str = ", world!";
    printf("%s\n", dest_str);
    unsigned int total = ft_strlcat(dest_str, src_str, sizeof(dest_str));
    if (total > sizeof(dest_str))
        printf("ERROR: CAN'T CONCAT FULL SRC STRING TO DEST. TOTAL - DSTSIZE = %lu\n", total - sizeof(dest_str));
    printf("%s\n", dest_str);
    
    return 0;
}