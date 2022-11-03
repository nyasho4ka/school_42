#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char* test_str = "wtf!!!";
    int len_test_str = ft_strlen(test_str);
    printf("test_str len: %d\n", len_test_str);

    char* test_str2 = "";
    int len_test_str2 = ft_strlen(test_str2);
    printf("test_str len: %d\n", len_test_str2);

    char test_str3[] = "wtf!!!";
    int len_test_str3 = ft_strlen(test_str3);
    printf("test_str len: %d\n", len_test_str3);

    char test_str4[] = "";
    int len_test_str4 = ft_strlen(test_str4);
    printf("test_str len: %d\n", len_test_str4);
}