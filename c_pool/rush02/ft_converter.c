#ifndef __FT_CONVERTER__
#define __FT_CONVERTER__
#include <stdlib.h>
#include <stdio.h>
#include "ft.h"

static char *ft_strjoin(int size, char** strs, char* sep)
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

char* ft_find_char(char* line, char c)
{
    int i = 0;
    while (line[i])
    {
        if (c == line[i])
            return line + i;
        i++;
    }
    return (void*)(0);
}

static int ft_strcmp(const char* s1, const char* s2)
{
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s1[i] - s2[i];
}

static char* ft_find_number_repr(char* line, t_numbers_dict* dict)
{
    for (int i = 0; i < dict->size; i++)
    {
        int cmp = ft_strcmp(line, dict->elements[i]->number);
        if (cmp == 0)
            return dict->elements[i]->repr;
    }
    return (void*)(0);
}

static char* get_one_digit_number(char* number, int start, t_numbers_dict* dict)
{
    char* one_digit_number = (char*)malloc(sizeof(char) * 2);
    one_digit_number[0] = number[start];
    one_digit_number[1] = '\0';
    return ft_find_number_repr(one_digit_number, dict);
}

char* get_two_digit_number(char* number, int start, t_numbers_dict* dict)
{
    if (number[start - 1] == '0')
    {
        if (number[start] == '0')
            return (void*)(0);
        return get_one_digit_number(number, start, dict);
    }
    if (number[start - 1] == '1' || number[start] == '0')
    {
        char* two_digit = (char*)malloc(sizeof(char) * 3);
        two_digit[0] = number[start - 1];
        two_digit[1] = number[start];
        two_digit[2] = '\0';
        return ft_find_number_repr(two_digit, dict);
    }
    char* first_digit = (char*)malloc(sizeof(char) * 2);
    first_digit[0] = number[start];
    first_digit[1] = '\0';

    char* second_digit = (char*)malloc(sizeof(char) * 3);
    second_digit[0] = number[start - 1];
    second_digit[1] = '0';
    second_digit[2] = '\0';

    char** full_digit = (char**)malloc(sizeof(char*) * 2);
    full_digit[0] = ft_find_number_repr(second_digit, dict);
    full_digit[1] = ft_find_number_repr(first_digit, dict);
    free(first_digit);
    free(second_digit);
    return ft_strjoin(2, full_digit, " ");
}

char* get_three_digit_number(char* number, int triplet_start, t_numbers_dict* dict)
{
    char* two_digit_number = get_two_digit_number(number, triplet_start, dict);
    if (number[triplet_start - 2] == '0')
        return two_digit_number;
    char* three_digit_number = get_one_digit_number(number, triplet_start - 2, dict);
    char* hundred_string = (char *)malloc(sizeof(char) * 8);
    hundred_string = "hundred";
    if (two_digit_number)
    {
        char** final_string = (char**)malloc(sizeof(char*) * 3);
        final_string[0] = three_digit_number;
        final_string[1] = hundred_string;
        final_string[2] = two_digit_number;
        return ft_strjoin(3, final_string, " ");
    }
    else
    {
        char** final_string = (char**)malloc(sizeof(char*) * 2);
        final_string[0] = three_digit_number;
        final_string[1] = hundred_string;
        return ft_strjoin(2, final_string, " ");
    }
}

static char* get_big_round(int pos_counter, t_numbers_dict* dict)
{
    char* number = (char*)malloc(sizeof(char) * pos_counter + 2);
    number[0] = '1';
    for (int i = 1; i < pos_counter + 1; i++)
    {
        number[i] = '0';
    }
    number[pos_counter + 1] = '\0';
    return ft_find_number_repr(number, dict);
}

static char* get_big_round_name(int pos_counter, t_numbers_dict* dict)
{
    char* big_round_number = get_big_round(pos_counter, dict);
    if (big_round_number == (void*)(0))
        return (void*)(0);
    char* space_position = ft_find_char(big_round_number, ' ');
    return space_position + 1;
}

static char* fill_triplet(char* number, int triplet_start, int triplet_end, t_numbers_dict* dict)
{
    int pos_count = triplet_start - triplet_end;
    if (
        pos_count == 0 
        || (pos_count == 1 && number[triplet_start - 1] == '0' && number[triplet_start] != '0') 
        || (pos_count == 2 && number[triplet_start - 1] == '0' && number[triplet_start - 2] == '0' && number[triplet_start] != '0'))
        return get_one_digit_number(number, triplet_start, dict);
    if (pos_count == 1 || (pos_count == 2 && number[triplet_end] == '0'))
        return get_two_digit_number(number, triplet_start, dict);
    
    return get_three_digit_number(number, triplet_start, dict);
}

static char* ft_convert_by_three(char* line, int number_size, t_numbers_dict* dict)
{
    int number_of_triplets = number_size % 3 == 0 ? number_size / 3 : number_size / 3 + 1;
    int actual_triplets_number = 0;
    char** triplets;
    int pos_counter = 0;
    int triplet = number_of_triplets - 1;
    while (triplet >= 0)
    {
        char* triplet_string = fill_triplet(line, number_size - 1, number_size - 3 >= 0 ? number_size - 3 : 0, dict);
        if (triplet_string)
        {
            if (pos_counter > 0)
            {
                char* big_round_name = get_big_round_name(pos_counter, dict);
                if (big_round_name == (void*)(0))
                    return (void*)(0);
                char** triplet_elements = (char**)malloc(sizeof(char*) * 2);
                triplet_elements[0] = triplet_string;
                triplet_elements[1] = big_round_name;
                triplet_string = ft_strjoin(2, triplet_elements, " ");
            }
            actual_triplets_number++;
            char** temp_triplets = (char**)malloc(sizeof(char*) * actual_triplets_number);
            for (int i = actual_triplets_number - 1; i > 0; i--)
            {
                temp_triplets[i] = triplets[i - 1];
            }
            temp_triplets[0] = triplet_string;
            triplets = temp_triplets;
        }
        triplet--;
        pos_counter+=3;
        number_size-=3;
    }
    return ft_strjoin(actual_triplets_number, triplets, " ");
}

char* ft_convert(char* line, t_numbers_dict* dict)
{
    int number_size = ft_strlen(line);
    char* big_number = ft_convert_by_three(line, number_size, dict);
    return big_number;
}
#endif