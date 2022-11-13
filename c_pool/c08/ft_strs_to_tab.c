#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

int ft_strlen(char* str)
{
    int i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char* ft_strcopy(char* str, int size)
{
    char* str_copy = (char *)malloc(sizeof(char) * size + 1);

    int i = 0;
    while (i <= size)
    {   
        str_copy[i] = str[i];
        i++;
    }
    return str_copy;
}

t_stock_str create_stock_str(char* str)
{
    int size = ft_strlen(str);
    t_stock_str stock_str = {
        size,
        str,
        ft_strcopy(str, size),
    };
    return stock_str;
}

t_stock_str *ft_strs_to_tab(int ac, char **av)
{
    t_stock_str *stock_str_tab;
    if ((stock_str_tab = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1))) == ((void*)(0)))
        return (void*)(0);
    
    int i = 0;
    while (i < ac)
    {
        stock_str_tab[i] = create_stock_str(av[i]);
        i++;
    }

    stock_str_tab[i].size = 0;

    return stock_str_tab;
}

int main(int argc, char **argv)
{
    t_stock_str *stock_str = ft_strs_to_tab(argc, argv);
    printf("stock_str[0].size %d\n", stock_str[0].size);
}