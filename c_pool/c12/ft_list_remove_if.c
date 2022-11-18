#include <stdio.h>
#include <stdlib.h>
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

void free_fct(void* data_ptr)
{
    free(data_ptr);
}

int ft_strcmp(char* s1, char* s2)
{
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s1[i] - s2[i];
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, int(*cmp)(), void(*free_fct)(void*))
{
    t_list* temp;
    // take begin
    while ((*cmp)((*begin_list)->data, data_ref) == 0)
    {
        temp = (*begin_list)->next;
        (*free_fct)(*begin_list);
        *begin_list = temp;
    }

    t_list* curr = *begin_list;
    while(curr->next)
    {
        if ((*cmp)(curr->next->data, data_ref) == 0)
        {
            temp = curr->next->next;
            (*free_fct)(curr->next);
            curr->next = temp;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    char* comp_string = "hello";
    t_list* list = ft_create_elem("hello");
    list->next = ft_create_elem("hello");
    list->next->next = ft_create_elem("excuse");
    list->next->next->next = ft_create_elem("me");
    list->next->next->next->next = ft_create_elem("i");
    list->next->next->next->next->next = ft_create_elem("say");
    list->next->next->next->next->next->next = ft_create_elem("hello");
    list->next->next->next->next->next->next->next = ft_create_elem("sir?");
    list->next->next->next->next->next->next->next->next = ft_create_elem("hello!!!");
    list->next->next->next->next->next->next->next->next->next = ft_create_elem("hello");
    printf("BEFORE REMOVING\n");
    ft_print_list(list);
    ft_list_remove_if(&list, comp_string, &ft_strcmp, &free_fct);
    printf("AFTER REMOVING\n");
    ft_print_list(list);
    return (0);
}