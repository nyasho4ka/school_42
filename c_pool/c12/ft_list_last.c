#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

t_list *ft_create_elem(void *data)
{
    t_list *elem = (t_list*)malloc(sizeof(t_list));
    if (elem)
    {
        elem->data = data;
        elem->next = NULL;
    }
    return elem;
}

t_list* ft_list_last(t_list* begin_list)
{
    while (begin_list->next)
        begin_list = begin_list->next;
    return begin_list;
}

int main()
{
    t_list* list = ft_create_elem("hello");
    list->next = ft_create_elem("world");
    list->next->next = ft_create_elem("end!");
    printf("%s\n", (char*)ft_list_last(list)->data);
    return (0);
}