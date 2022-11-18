#include <stdio.h>
#include "ft_list.h"

void ft_list_push_back(t_list** begin_list, void* data)
{
    t_list* elem = ft_create_elem(data);
    if (*begin_list)
    {
        t_list* end = *begin_list;
        while(end->next)
        {
            end = end->next;
        }
        
        end->next = elem;
    }
    else{
        *begin_list = ft_create_elem(data);
    }
}

int main()
{
    t_list* list = (void*)(0);
    ft_list_push_back(&list, "hello");
    ft_list_push_back(&list, "world");
    ft_list_push_back(&list, "!");
    ft_list_push_back(&list, "finally");
    ft_list_push_back(&list, "right");
    ft_list_push_back(&list, "order");

    t_list* curr = list;
    while (curr)
    {   
        printf("%s\n", (char*)curr->data);
        curr = curr->next;
    }
    return (0);
}