#include <stdio.h>
#include "ft_list.h"

void ft_list_push_front(t_list **begin_list, void *data)
{
    t_list* begin = ft_create_elem(data);
    if (begin)
    {
        begin->next = *begin_list;
        *begin_list = begin;
    }
}

int main()
{
    t_list* list = ft_create_elem("hello");
    ft_list_push_front(&list, "world");
    ft_list_push_front(&list, "is");
    ft_list_push_front(&list, "it");
    ft_list_push_front(&list, "reversed");
    ft_list_push_front(&list, "?");
    t_list* curr = list;
    while (curr)
    {
        printf("%s\n", (char*)curr->data);
        curr = curr->next;
    }
    return (0);
}