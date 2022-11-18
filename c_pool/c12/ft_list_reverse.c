#include <stdio.h>
#include "ft_list.h"

void ft_print_list(t_list* list)
{
    t_list* curr = list;
    printf("------------------\n");
    while (curr)
    {
        printf("%s\n", (char*)curr->data);
        curr = curr->next;
    }
    printf("------------------\n");
}

void ft_list_reverse(t_list** begin_list)
{
    t_list* curr = *begin_list;
    if (!curr || !curr->next)
        return;

    t_list* tmp = (void*)(0);
    t_list* prev = (void*)(0);

    while (curr)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    
    *begin_list = prev;
}

int main()
{
    t_list* list = ft_create_elem("hello");
    list->next = ft_create_elem("world");
    list->next->next = ft_create_elem("again");
    list->next->next->next = ft_create_elem("or");
    list->next->next->next->next = ft_create_elem("reverse");
    printf("BEFORE REVERSE:\n");
    ft_print_list(list);
    ft_list_reverse(&list);
    printf("AFTER REVERSE:\n");
    ft_print_list(list);
    return (0);
}