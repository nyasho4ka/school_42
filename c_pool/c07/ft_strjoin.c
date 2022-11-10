#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char** strs, char* sep)
{
    if (size == 0)
        return malloc(sizeof(char) * 0);

    int sep_count = size - 1;
    int all_char_count = 0;
    
    for (int i = 0; i < size; i++)
    {
        int char_count = 0;
        char* str = strs[i];
        while (str[char_count])
            char_count++;
        all_char_count += char_count;
    }
    char* result = malloc(sizeof(char) * all_char_count + sep_count + 1);
    
    char* word = strs[0];
    int char_count = 0;
    while (word[char_count])
    {
        result[char_count] = word[char_count];
        char_count++;
    }

    for (int i = 1; i < size; i++)
    {
        result[char_count] = *sep;
        char_count++;

        word = strs[i];
        int curr_char_count = 0;
        while (word[curr_char_count])
        {
            result[char_count] = word[curr_char_count];
            char_count++;
            curr_char_count++;
        }
    }

    result[char_count] = '\0';
    return result;
}

int main()
{
    char* hello = "hello";
    char* my = "my";
    char* lady = "lady";
    char** strs = &hello;
    *(strs + 1) = my;
    *(strs + 2) = lady;
    char* sep = ",";
    int size = 3;
    char* result = ft_strjoin(size, strs, sep);
    printf("%s\n", result);
    return (0);
}