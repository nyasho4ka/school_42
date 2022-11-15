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

    int empty_number = 0;
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

static int ft_strcmp(const char* s1, const char* s2)
{
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s1[i] - s2[i];
}

static int get_zero_count(char* line, int start, int end)
{
    int zero_count = 0;
    for (int i = end; i <= start; i++)
    {
        if (line[i] == '0')
            zero_count++;
    }
    return zero_count;
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

static char* get_one_digit_number(char* line, int digit)
{
    char* one_digit_number;
    if ((one_digit_number = (char*)malloc(sizeof(char) * 2)) == (void*)(0))
        return (void*)(0);
    
    one_digit_number[0] = line[digit];
    one_digit_number[1] = '\0';
    return one_digit_number;
}

static char* get_two_digit_number(char* line, int digit)
{
    char* two_digit_number;
    if((two_digit_number = (char*)malloc(sizeof(char) * 3)) == (void*)(0))
        return (void*)(0);

    two_digit_number[0] = line[digit];
    two_digit_number[1] = '0';
    two_digit_number[2] = '\0';
    return two_digit_number;
}

static char* get_big_round_number(int pos_counter)
{
    char* big_round_number = (char*)malloc(sizeof(char) * (pos_counter + 1));
    big_round_number[0] = '1';
    for (int i = 1; i < pos_counter; i++)
        big_round_number[i] = '0';
    big_round_number[pos_counter] = '\0';
    return big_round_number;
}

static char* fill_triplet(char* number, int triplet_start, int triplet_end, int pos_counter, t_numbers_dict* dict)
{
    (void) pos_counter;
    (void) dict;
    int elem_count = triplet_start - triplet_end;
    int zero_count = get_zero_count(number, triplet_start, triplet_end);
    char** triplet;
    if (zero_count == 0 && elem_count >= 2 && number[triplet_start - 1] == '1')
    {
        elem_count--;
    }
    else
    {
        elem_count -= zero_count;
    }
    triplet = (char**)malloc(sizeof(char*) * elem_count);

    int triplet_pos = elem_count - 1;

    for (int i = triplet_start; i >= triplet_end; i--)
    {
        if (number[i] == '0')
            continue;
        
        triplet[triplet_pos];
        triplet_pos--;
    }

    return ft_strjoin(elem_count, triplet, " ");
}

static char* ft_convert_by_three(char* line, int number_size, t_numbers_dict* dict)
{
    int number_of_triplets = number_size % 3 == 0 ? number_size / 3 : number_size / 3 + 1;
    printf("number_of_triplets: %d\n", number_of_triplets);
    char** triplets = (char**)malloc(sizeof(char*) * number_of_triplets);
    int pos_counter = 0;
    for (int triplet = number_of_triplets - 1; triplet >= 0; triplet--)
    {
        triplets[triplet] = fill_triplet(line, number_size - 1, number_size - 3 >= 0 ? number_size - 3 : 0, pos_counter, dict);
        pos_counter += 3;
        number_size -= 3;
    }
    return ft_strjoin(number_of_triplets, triplets, " ");
}

static char* ft_convert_after_19(char* line, int number_size, t_numbers_dict* dict)
{
    int zero_count = get_zero_count(line, 0, 1);
    int digit_count = number_size - zero_count;
    char** digits = (char**)malloc(sizeof(char*) * (digit_count));
    if (digits == (void*)(0))
        return (void*)(0);
    

    char *quant;
    char *quant_repr;
    char *big_round;
    char *big_round_repr;

    int digit_pos = digit_count - 1;
    int pos_counter = 0;
    for (int digit = number_size - 1; digit >= 0; digit--)
    {        
        pos_counter++;
        if (line[digit] == '0')
            continue;

        if (pos_counter == 1)
        {
            quant = get_one_digit_number(line, digit);
            if (quant == (void*)(0))
                return (void*)(0);
            quant_repr = ft_find_number_repr(quant, dict);
            free(quant);
            if (quant_repr == (void*)(0))
                return (void*)(0);
            digits[digit_pos] = quant_repr;
        }
        else if (pos_counter == 2)
        {
            quant = get_two_digit_number(line, digit);
            if (quant == (void*)(0))
                return (void*)(0);

            quant_repr = ft_find_number_repr(quant, dict);
            free(quant);
            if (quant_repr == (void*)(0))
                return (void*)(0);
            digits[digit_pos] = quant_repr;
        }
        else
        {
            big_round = get_big_round_number(pos_counter);
            if (big_round == (void*)(0))
                return (void*)(0);

            big_round_repr = ft_find_number_repr(big_round, dict);
            if (big_round_repr == (void*)(0))
                return (void*)(0);

            digits[digit_pos] = big_round_repr;
        }
        digit_pos--;
    }
    return ft_strjoin(number_size - zero_count, digits, " ");
}

char* ft_convert(char* line, t_numbers_dict* dict)
{
    int number_size = ft_strlen(line);
    // at first we need to deal with number < 20
    if (number_size == 1 || (number_size == 2 && line[0] == '1'))
    {
        char* two_digit_number = ft_find_number_repr(line, dict);
        return two_digit_number;
    }
    char* big_number = ft_convert_by_three(line, number_size, dict);
    return big_number;
}
#endif