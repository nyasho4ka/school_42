#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void free_fct(void *data)
{
    free(data);
}

void ft_list_clear(t_list* begin_list, void(*free_fct)(void *))
{
    t_list* curr = begin_list;
    t_list* tmp = (void*)(0);
    while (curr)
    {
        tmp = curr->next;
        if (curr->data)
            (*free_fct)(curr->data);
        (*free_fct)(curr);
        curr = tmp;
    }
}

int main()
{
    char* hello = (char*)malloc(sizeof(char) * 6);
    hello[0] = 'h';
    hello[1] = 'e';
    hello[2] = 'l';
    hello[3] = 'l';
    hello[4] = 'o';
    hello[5] = '\0';

    char* world = (char*)malloc(sizeof(char) * 6);
    world[0] = 'w';
    world[1] = 'o';
    world[2] = 'r';
    world[3] = 'l';
    world[4] = 'd';
    world[5] = '\0';

    char* again = (char*)malloc(sizeof(char) * 7);
    again[0] = 'a';
    again[1] = 'g';
    again[2] = 'a';
    again[3] = 'i';
    again[4] = 'n';
    again[5] = '!';
    again[6] = '\0';

    t_list* list = ft_create_elem(hello);
    list->next = ft_create_elem(world);
    list->next->next = ft_create_elem(again);
    ft_list_clear(list, &free_fct);
    return (0);
}
