#include <stdio.h>
#include "ft_list.h"

t_list* ft_list_push_strs(int size, char** strs)
{
    t_list* list = (void*)(0);
    for (int i = 0; i < size; i++)
    {
        t_list* elem = ft_create_elem(strs[i]);
        if (elem)
        {
            elem->next = list;
            list = elem;
        }
    }
    return list;
}

int main(int argc, char** argv)
{
    t_list* res = ft_list_push_strs(argc, argv);
    t_list* curr = res;
    while (curr)
    {
        printf("%s\n", (char*)curr->data);
        curr = curr->next;
    }
    return (0);
}