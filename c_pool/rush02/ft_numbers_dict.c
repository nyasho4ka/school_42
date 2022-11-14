#ifndef __FT_NUMBERS_DICT__
#define __FT_NUMBERS_DICT__
#include <stdlib.h>
#include <stdio.h>
#include "ft.h"

t_numbers_dict* create_dict(int size)
{
    t_numbers_dict* dict = (t_numbers_dict*)malloc(sizeof(t_numbers_dict));
    dict->curr_elem = 0;
    dict->size = size;
    t_dict_elem** elements = (t_dict_elem**)malloc(sizeof(t_dict_elem*));
    dict->elements = elements;
    return dict;
}

static char* fill_elem(char* line, char** number, char** repr)
{
    int pos = 0;
    while (line[pos])
    {
        if (line[pos] <= '0' || line[pos] >= '9')
            break;
        pos++;
    }

    char *n;
    if ((n = (char*)malloc(sizeof(char) * (pos + 1))) == (void*)(0))
        return (void*)(0);

    for (int i = 0; i < pos; i++)
        n[i] = line[i];
    n[pos] = '\0';
    *number = n;
    
    // until repr
    while (line[pos] && (line[pos] == ':' || line[pos] == ' '))
        pos++;

    int repr_size = 0;
    int repr_begin = pos;
    while (line[pos])
    {
        pos++;
        repr_size++;
    }

    char* rp;
    if ((rp = (char*)malloc(sizeof(char) * (repr_size + 1))) == (void*)(0))
        return (void*)(0);
    
    for (int i = 0; i < repr_size; i++)
    {
        rp[i] = line[repr_begin + i]; 
    }
    rp[repr_size] = '\0';

    *repr = rp;
    return line;
}

static t_dict_elem* create_elem(char* line)
{
    t_dict_elem* elem = (t_dict_elem*)malloc(sizeof(t_dict_elem));
    char* number = (void*)(0);
    char* repr = (void*)(0);
    fill_elem(line, &number, &repr);
    elem->number = number;
    elem->repr = repr;
    return elem;
}

int add_elem(t_numbers_dict* dict, char* line)
{
    if (dict->curr_elem == dict->size)
        return 0;
    dict->elements[dict->curr_elem] = create_elem(line);
    dict->curr_elem++;
    return 1;
}

void print_dict(t_numbers_dict* dict)
{
    for (int i = 0; i < dict->curr_elem; i++)
    {
        t_dict_elem* elem = dict->elements[i];
        printf("%s : %s\n", elem->number, elem->repr);
    }
}
#endif