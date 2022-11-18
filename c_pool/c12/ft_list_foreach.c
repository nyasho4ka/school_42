#include <stdio.h>
#include "ft_list.h"

void ft_list_foreach(t_list* begin_list, void(*f)(void*))
{
    t_list* curr = begin_list;
    while (curr)
    {
        if (curr->data)
            (*f)(curr->data);
        curr = curr->next;
    }
}
