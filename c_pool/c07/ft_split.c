#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

int ft_is_in_str(char c, char* str)
{
    while (*str)
    {
        if (c == *str++)
        {
            return 1;
        }
    }
    return 0;
}

int get_word_count(char* str, char* charset)
{
    int word_count = 0;
    int curr_char = 0;
    int word_begin = 0;
    while (str[curr_char])
    {
        if (ft_is_in_str(str[curr_char], charset))
        {
            if (curr_char != word_begin)
            {
                word_count++;
            }
            curr_char++;
            word_begin = curr_char;
        }
        else {
            curr_char++;
        }
    }
    if (curr_char != word_begin)
    {
        word_count++;
    }
    return word_count;
}

char* create_word(char* str, int word_begin, int word_end)
{
    char* word;
    int word_size = word_end - word_begin;
    if ((word = (char*)malloc(sizeof(char) * (word_size + 1))) == (void*)(0))
        return (void *)(0);

    int char_index = 0;
    for (int i = word_begin; i < word_end; i++)
    {
        word[char_index] = str[i];
        char_index++;
    }
    word[char_index] = '\0';
    return word;
}

char** ft_split(char* str, char* charset)
{
    char** words;
    int word_count = 0;
    int word_start = 0;
    int word_end = 0;
    int index = 0;

    if ((word_count = get_word_count(str, charset)))
    {
        if ((words = (char**)malloc(sizeof(char*) * (word_count + 1))) == ((void *)0))
            return (void *)(0);
        
        while (index < word_count)
        {
            // find word start
            while (ft_is_in_str(str[word_start], charset))
                word_start++;

            // find word end
            word_end = word_start + 1;  // + 1 because we already know that str[word_start] is not in charset
            while (!ft_is_in_str(str[word_end], charset))
                word_end++;
            
            words[index] = create_word(str, word_start, word_end);

            word_start = word_end + 1;  // continue from position where curr word ends. + 1 because we know that str[word_end] is in charset
            index++;
        }
    }
    else
        words = (char **)malloc(sizeof(char*));

    words[index] = (void *)(0);

    return words; 
}

int main()
{
    char* str = "abdddbdbdoobbbbb";
    char* charset = "b";
    char** spl = ft_split(str, charset);

    printf("str: %s, charset: %s\n", str, charset);
    printf("print every word:\n");
    int i = 0;
    while (spl[i] != (void *)(0))
    {
        printf("%s\n", spl[i]);
        i++;
    }    
}