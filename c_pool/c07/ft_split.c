#include <stdio.h>
#include <stdlib.h>

int is_start_with(char* str, char* charset)
{
    int i = 0;
    while (charset[i])
    {
        if (str[i] != charset[i])
            return 0;
        i++;
    }
    return 1;
}

int* get_indecies(char* str, char* charset, int charset_size)
{
    int char_pos = 0;

    while (str[char_pos])
    {
        char_pos++;
    }
    int* indecies = malloc(sizeof(int) * char_pos);

    char_pos = 0;
    int begin_pos = 0;
    int indecies_counter = 0;
    while (str[char_pos])
    {
        if (is_start_with(str + char_pos, charset))
        {
            if (char_pos != begin_pos)
            {
                indecies[indecies_counter] = begin_pos;
                indecies_counter++;
            }
            char_pos += charset_size;
        }
        else
        {
            char_pos++;
        }
    }

    return indecies;
}

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char** ft_split(char* str, char* charset)
{
    int charset_size = ft_strlen(charset);
    int word_count = get_word_count(str, charset, charset_size);
    char** words = malloc(sizeof(char*) * word_count);

}

int main()
{
    printf("str: abbbdboob, charset: b, word_count: %d\n", get_word_count("abbbdboob", "b", 1));
}