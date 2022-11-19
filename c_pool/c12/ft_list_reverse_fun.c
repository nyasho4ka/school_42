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

int ft_list_size(t_list* begin_list)
{
    int i = 0;
    while (begin_list)
    {
        begin_list = begin_list->next;
        i++;
    }
    return i;
}

void ft_list_reverse_fun(t_list* begin_list)
{
    int list_size = ft_list_size(begin_list);

    if (!begin_list || !begin_list->next)
        return;

    while (list_size)
    {
        t_list* curr = begin_list;
        for (int i = 0; i < list_size - 1; i++)
        {
            t_list tmp;
            tmp.data = curr->next->data;
            curr->next->data = curr->data;
            curr->data = tmp.data;
            curr = curr->next;
        }
        list_size--;
    }
}

int main()
{
    t_list* list = ft_create_elem("hello");
    list->next = ft_create_elem("world");
    list->next->next = ft_create_elem("agagin?");
    ft_print_list(list);
    ft_list_reverse_fun(list);
    ft_print_list(list);
    return (0);
}