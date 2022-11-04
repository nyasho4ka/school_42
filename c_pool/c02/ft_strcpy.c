#include <stdio.h>

char* ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (*(src + i) != '\0')
    {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = '\0';
    return dest;
}

int main()
{   
    // empty string test case
    char* empty_string = "";
    char empty_test_buf[4];
    ft_strcpy(empty_test_buf, empty_string);
    // check null char
    printf("(int)empty_test_buf[0]: %d\n", (int)empty_test_buf[0]);

    char* non_empty_string = "non empty string";
    char non_empty_test_buf[32];
    ft_strcpy(non_empty_test_buf, non_empty_string);
    // check copy
    printf("non_empty_test_buf: %s\n", non_empty_test_buf);

    return 0;
}