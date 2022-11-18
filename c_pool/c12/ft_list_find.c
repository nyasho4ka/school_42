#include "ft_list.h"

t_list *ft_list_find(t_list* begin_list, void* data_ref, int (*cmp)(void*, void*))
{
    t_list* curr = begin_list;
    while (curr)
    {
        if ((*cmp)(curr->data, data_ref) == 0)
            break;
        curr = curr->next;
    }
    return curr;
}