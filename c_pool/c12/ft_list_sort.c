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
        printf("%s\n", (char*)curr->data);
        curr = curr->next;
    }
    printf("------------------\n");
}

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

int main()
{
    t_list* list = ft_create_elem("hello");
    list->next = ft_create_elem("world");
    list->next->next = ft_create_elem("apple");
    list->next->next->next = ft_create_elem("bolly");
    ft_print_list(list);
    ft_list_sort(&list, &ft_strcmp);
    ft_print_list(list);
    return (0);
}