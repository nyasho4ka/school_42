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

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char** get_indecies(char* str, char* charset, int charset_size)
{
    int char_pos = 0;
    while (str[char_pos])
        char_pos++;
    
    // cannot be more than half of char seps;
    int indecies_count = char_pos % 2 == 0 ? char_pos / 2 + 1: char_pos / 2 + 2;
    char** indecies = malloc(sizeof(char*) * indecies_count);

    char_pos = 0;
    int begin_word_pos = 0;
    int index = 0;

    while (str[char_pos])
    {
        if (is_start_with(str + char_pos, charset))
        {
            if (char_pos != begin_word_pos)
            {
                indecies[index] = str + begin_word_pos;
                index++;
            }
            char_pos += charset_size;
            begin_word_pos = char_pos;
        }
        else
        {
            char_pos++;
        }
    }
    // Add last word
    if (str[begin_word_pos])
    {
        indecies[index] = str + begin_word_pos;
        index++;
    }

    indecies[index] = 0;

    return indecies;
}

char** ft_split(char* str, char* charset)
{
    int charset_size = ft_strlen(charset);
    return get_indecies(str, charset, charset_size);
}

int main()
{
    char* str = "abdddbdbdoob";
    char* charset = "bd";
    char** spl = ft_split(str, charset);

    printf("str: %s, charset: %s\n", str, charset);
    int i = 0;
    while (spl[i] != 0)
    {
        printf("index: %d, char: %c\n", i, spl[i][0]);
        i++;
    }    
}