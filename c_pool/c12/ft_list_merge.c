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

void ft_list_merge(t_list** begin_list1, t_list* begin_list2)
{
    t_list* curr = *begin_list1;
    if (curr == (void*)(0))
    {
        *begin_list1 = begin_list2;
        return;
    }
    // go until last elem
    while(curr->next)
    {
        curr = curr->next;
    }
    curr->next = begin_list2;
}

int main()
{
    t_list* list = ft_create_elem("hello");
    list->next = ft_create_elem("world");
    list->next->next = ft_create_elem("!");

    t_list* empty_list = (void*)(0);

    t_list* list2 = ft_create_elem("Is");
    list2->next = ft_create_elem("it");
    list2->next->next = ft_create_elem("another");
    list2->next->next->next = ft_create_elem("sentence?? ?");
    printf("before merging list\n");
    ft_print_list(list);
    ft_list_merge(&list, list2);
    printf("after merging list\n");
    ft_print_list(list);
    printf("\n");
    printf("before merging empty list\n");
    ft_print_list(empty_list);
    ft_list_merge(&empty_list, list2);
    printf("after merging empty list\n");
    ft_print_list(empty_list);
    return (0);
}