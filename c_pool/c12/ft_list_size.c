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

int ft_list_size(t_list* begin_list)
{
    int count = 0;
    t_list* curr = begin_list;
    while (curr)
    {
        curr = curr->next;
        count++;
    }
    return count;
}

int main()
{
    t_list* non_empty_list = (void*)(0);
    ft_list_push_front(&non_empty_list, "hello");
    ft_list_push_front(&non_empty_list, "world");
    ft_list_push_front(&non_empty_list, "what");
    ft_list_push_front(&non_empty_list, "is");
    ft_list_push_front(&non_empty_list, "a");
    ft_list_push_front(&non_empty_list, "list");
    ft_list_push_front(&non_empty_list, "size");
    ft_list_push_front(&non_empty_list, "?");
    ft_list_push_front(&non_empty_list, "right");
    ft_list_push_front(&non_empty_list, "answer");
    ft_list_push_front(&non_empty_list, "is");
    ft_list_push_front(&non_empty_list, "12");
    printf("non_empty_list size: %d\n", ft_list_size(non_empty_list));
    t_list* empty_list = NULL;
    printf("empty_list size: %d\n", ft_list_size(empty_list));
    return (0);
}