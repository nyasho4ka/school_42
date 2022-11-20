#include <stdio.h>
#include <unistd.h>
#include "ft_list.h"

int ft_strcmp(char* s1, char* s2)
{
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s1[i] - s2[i];
}

void ft_print_list(t_list* list)
{
    t_list* curr = list;
    printf("------------------\n");
    while (curr)
    {
        printf("%s, curr: %p, curr->next: %p\n", (char*)curr->data, curr, curr->next);
        curr = curr->next;
    }
    printf("------------------\n");
}

char buff[20];

void ft_list_sort(t_list** begin_list, int(*cmp)())
{
    t_list* curr = *begin_list;
    if (curr == (void*)(0))
        return;

    t_list tmp;
    t_list* tmp_next;
    while (curr->next)
    {
        t_list* inner = curr->next;
        while (inner)
        {
            if ((*cmp)(inner->data, curr->data) < 0)
            {
                tmp = *curr;
                tmp_next = curr->next;
                *curr = *inner;
                *inner = tmp;
                inner->next = curr->next;
                curr->next = tmp_next;
            }
            inner = inner->next;
        }
        curr = curr->next;
    }
}

void ft_swap_nodes(t_list** first, t_list** second)
{
    t_list* tmp_ptr1 = *first;
    t_list* tmp_next1 = (*first)->next;
    t_list* tmp_ptr2 = *second;
    t_list* tmp_next2 = (*second)->next;
    tmp_ptr2->next = tmp_next1;
    tmp_ptr1->next = tmp_next2;
    *second = tmp_ptr1;
    *first = tmp_ptr2;
    read(0, buff, 10);
}

// todo: using pointer on pointer can't help with neigbour elements
void ft_list_sort_advanced(t_list** begin_list, int(*cmp)())
{
    (void)(*cmp);
    t_list** curr = begin_list;
    t_list** inner = &((*curr)->next);
    while (*inner)
    {
        ft_swap_nodes(curr, inner);
        inner = &((*inner)->next);
    }
}

int main()
{
    t_list* list = ft_create_elem("world");
    list->next = ft_create_elem("hello");
    list->next->next = ft_create_elem("bolly");
    list->next->next->next = ft_create_elem("apple");

    ft_print_list(list);
    ft_list_sort(&list, &ft_strcmp);
    ft_print_list(list);
    return (0);
}