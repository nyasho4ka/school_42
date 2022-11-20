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

char buf[10];

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int(*cmp)())
{
    t_list** curr1 = begin_list1;

    while (*curr1 && begin_list2)
    {
        if ((*cmp)(begin_list2->data, (*curr1)->data) < 0)
        {
            t_list* tmp_curr2 = begin_list2;
            begin_list2 = begin_list2->next;
            tmp_curr2->next = *curr1;
            (*curr1) = tmp_curr2;
        }
        curr1 = &(*curr1)->next;
    }
    if (begin_list2)
        (*curr1) = begin_list2;
}

int main()
{
    t_list* list = ft_create_elem("a");
    list->next = ft_create_elem("b");
    list->next->next = ft_create_elem("d");
    list->next->next->next = ft_create_elem("o");
    list->next->next->next->next = ft_create_elem("w");

    t_list* list2 = ft_create_elem("c");
    list2->next = ft_create_elem("e");
    list2->next->next = ft_create_elem("g");
    list2->next->next->next = ft_create_elem("j");
    list2->next->next->next->next = ft_create_elem("z");
    list2->next->next->next->next->next = ft_create_elem("zetta");
    list2->next->next->next->next->next = ft_create_elem("zollo");
    list2->next->next->next->next->next = ft_create_elem("zzzzz");

    printf("BEFORE:\n");
    ft_print_list(list);
    ft_print_list(list2);
    ft_sorted_list_merge(&list, list2, &ft_strcmp);  
    printf("AFTER: \n");
    ft_print_list(list);

    t_list* empty_list = (void*)(0);

    t_list* list3 = ft_create_elem("c");
    list3->next = ft_create_elem("e");
    list3->next->next = ft_create_elem("g");
    list3->next->next->next = ft_create_elem("j");
    list3->next->next->next->next = ft_create_elem("z");
    list3->next->next->next->next->next = ft_create_elem("zetta");
    list3->next->next->next->next->next = ft_create_elem("zollo");
    list3->next->next->next->next->next = ft_create_elem("zzzzz");

    printf("BEFORE:\n");
    ft_print_list(empty_list);
    ft_print_list(list3);
    ft_sorted_list_merge(&empty_list, list3, &ft_strcmp);
    printf("AFTER: \n");  
    ft_print_list(empty_list);

    t_list* list4 = ft_create_elem("a");
    list4->next = ft_create_elem("b");
    list4->next->next = ft_create_elem("d");
    list4->next->next->next = ft_create_elem("o");
    list4->next->next->next->next = ft_create_elem("w");

    t_list* empty_list2 = (void*)(0);

    printf("BEFORE:\n");
    ft_print_list(list4);
    ft_print_list(empty_list2);
    ft_sorted_list_merge(&list4, empty_list2, &ft_strcmp);    
    printf("AFTER: \n");
    ft_print_list(list4);

    t_list* list5 = ft_create_elem("a");
    list5->next = ft_create_elem("b");
    list5->next->next = ft_create_elem("d");
    list5->next->next->next = ft_create_elem("o");
    list5->next->next->next->next = ft_create_elem("w");

    t_list* list6 = ft_create_elem("c");
    list6->next = ft_create_elem("e");
    list6->next->next = ft_create_elem("g");

    printf("BEFORE:\n");
    ft_print_list(list5);
    ft_print_list(list6);
    ft_sorted_list_merge(&list5, list6, &ft_strcmp);
    printf("AFTER: \n");    
    ft_print_list(list5);
    return (0);
}