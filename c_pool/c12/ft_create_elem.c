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
