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

void ft_sorted_list_insert(t_list** begin_list, void* data, int(*cmp)())
{
    t_list** ptr = begin_list;
    t_list* tmp;

    while (*ptr && (*cmp)(data, (*ptr)->data) > 0)
    {
        if (ft_strcmp(data, "rofl") == 0)
        {
            printf("ptr: %p\n", ptr);
            printf("*ptr: %p\n", *ptr);
            printf("(*ptr)->next: %p\n", (*ptr)->next);
            printf("&((*ptr)->next): %p\n", &((*ptr)->next));
        }
        ptr = &((*ptr)->next);
        if (ft_strcmp(data, "rofl") == 0)
            printf("*ptr: %p\n", *ptr);
    }
    t_list* new_elem = ft_create_elem(data);
    tmp = *ptr;
    *ptr = new_elem;
    new_elem->next = tmp;
}

int main()
{
    t_list* list = (void*)(0);
    ft_sorted_list_insert(&list, "hello", &ft_strcmp);
    ft_sorted_list_insert(&list, "world", &ft_strcmp);
    ft_sorted_list_insert(&list, "ololo", &ft_strcmp);
    ft_sorted_list_insert(&list, "rofl", &ft_strcmp);
    ft_print_list(list);
    return (0);
}