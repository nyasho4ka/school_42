#include <stdio.h>

char* ft_strncpy(char *dest, const char *src, unsigned int n)
{
    unsigned int i = 0;
    while (*(src + i) != '\0' && i < n)
    {
        *(dest + i) = *(src + i);
        i++;
    }
    
    while (i < n)
    {
        *(dest + i) = '\0';
        i++;
    }

    return dest;
}

int main()
{
    char *empty_string = "";
    char emp_buff[7] = "hello";
    // check bytes before
    printf("bytes before\n");
    for (int i = 0; i < 5; i++)
        printf("position: %d, char: %c\n", i, emp_buff[i]);
    printf("\n");

    ft_strncpy(emp_buff, empty_string, sizeof(emp_buff));
    printf("bytes after\n");
    for (int i = 0; i < 5; i++)
        printf("position: %d, char: %d\n", i, (int)emp_buff[i]);
    printf("\n");

    char *non_empty_string = "non empty string";
    char non_empty_buff[20];
    ft_strncpy(non_empty_buff, non_empty_string, sizeof(non_empty_buff));
    printf("bytes after\n");
    for (unsigned int i = 0; i < sizeof(non_empty_buff); i++)
        printf("position: %d, char: %c\n", i, non_empty_buff[i]);
    printf("\n");

    return 0;
}