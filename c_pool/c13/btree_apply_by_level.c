#include <stdlib.h>
#include <stdio.h>
#include "ft_tree.h"

int btree_level_count(t_btree* root)
{
    int level_count = 0;
    if (root == (void*)(0))
        return level_count;
    
    level_count++;
    int left_level_count = btree_level_count(root->left);
    int right_level_count = btree_level_count(root->right);
    return left_level_count > right_level_count ? left_level_count + level_count : right_level_count + level_count;
}

void ft_putitem_by_level(void* item, int current_level, int is_first)
{
    if (current_level == 0)
    {
        printf("item: %s, is_first?: %d", (char*)((t_btree*)item)->item, is_first);
    }
    else if (current_level > 0)
    {
        ft_putitem_by_level(((t_btree*)item)->left, current_level - 1, is_first);
        printf("\t");
        ft_putitem_by_level(((t_btree*)item)->right, current_level - 1, 0);
    }
}

void btree_apply_by_level(t_btree* root, void(*applyf)(void* item, int current_level, int is_first))
{
    int tree_level = btree_level_count(root);
    for (int i = 0; i < tree_level; i++)
    {
        (*applyf)(root, i, 1);
        printf("\n");
    }
        

}

int main()
{
    t_btree* root = btree_create_node("25");
    root->left = btree_create_node("15");
    root->right = btree_create_node("50");
    root->left->left = btree_create_node("10");
    root->left->right = btree_create_node("22");
    root->right->left = btree_create_node("35");
    root->right->right = btree_create_node("70");
    root->left->left->left = btree_create_node("4");
    root->left->left->right = btree_create_node("12");
    root->left->right->left = btree_create_node("18");
    root->left->right->right = btree_create_node("24");
    root->right->left->left = btree_create_node("31");
    root->right->left->right = btree_create_node("44");
    root->right->right->left = btree_create_node("66");
    root->right->right->right = btree_create_node("90");

    btree_apply_by_level(root, &ft_putitem_by_level);
    return (0);
}