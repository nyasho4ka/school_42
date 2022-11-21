#include <unistd.h>
#include <stdio.h>
#include "ft_tree.h"

const char left_par = '[';
const char right_par = ']';
const char* arrow = "->";

void ft_putstr(void* line)
{
    char* line_char = (char*)line;
    int i = 0;
    while (line_char[i])
    {
        i++;
    }
    write(1, &left_par, 1);
    write(1, line, i);
    write(1, &right_par, 1);
    write(1, arrow, 2);
}

int ft_strcmp(void* v1, void* v2)
{
    char* s1 = (char*)v1;
    char* s2 = (char*)v2;
    int i = 0;
    while (s1[i] && (s1[i] == s2[i]))
    {
        i++;
    }
    return s1[i] - s2[i];
}

void btree_apply_infix(t_btree* root, void(*applyf)(void*))
{
    if (root == (void*)(0))
        return;

    btree_apply_infix(root->left, applyf);
    (*applyf)(root->item);
    btree_apply_infix(root->right, applyf);
}

void btree_insert_data(t_btree** root, void* item, int(*cmpf)(void*, void*))
{
    if (*root == (void*)(0))
    {
        t_btree* node = btree_create_node(item);
        *root = node;
    }
    else if ((*cmpf)(item, (*root)->item) < 0)
    {
        btree_insert_data(&(*root)->left, item, cmpf);
    }
    else if ((*cmpf)(item, (*root)->item) > 0)
    {
        btree_insert_data(&(*root)->right, item, cmpf);
    }
}

int main()
{
    t_btree* root = (void*)(0);

    btree_insert_data(&root, "25", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "15", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "50", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "10", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "22", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "35", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "70", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "4", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "12", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "18", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "24", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "31", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "44", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "66", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");
    btree_insert_data(&root, "90", &ft_strcmp);
    btree_apply_infix(root, &ft_putstr);
    printf("\n");

    return (0);
}