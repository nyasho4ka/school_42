#include <stdio.h>
#include "ft_list.h"

t_list* ft_list_at(t_list* begin_list, unsigned int nbr)
{
    unsigned int i = 0;
    t_list* curr = begin_list;
    while (i < nbr && curr)
    {
        curr = curr->next;
        i++;
    }
    return curr;
}

int main()
{
    t_list* list = ft_create_elem("hello");
    list->next = ft_create_elem("world");
    list->next->next = ft_create_elem("check");
    list->next->next->next = ft_create_elem("ft");
    list->next->next->next->next = ft_create_elem("list");
    list->next->next->next->next->next = ft_create_elem("at");
    printf("ft_list_at(0): %s\n", (char*)ft_list_at(list, 0)->data);
    printf("ft_list_at(1): %s\n", (char*)ft_list_at(list, 1)->data);
    printf("ft_list_at(2): %s\n", (char*)ft_list_at(list, 2)->data);
    printf("ft_list_at(3): %s\n", (char*)ft_list_at(list, 3)->data);
    printf("ft_list_at(20): %s\n", (char*)ft_list_at(list, 20));
    return (0);
}