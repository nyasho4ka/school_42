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

    printf("tree deep: %d\n", btree_level_count(root));
    root->left->left->left->left = btree_create_node("3");
    root->left->left->left->left->left = btree_create_node("2");
    root->left->left->left->left->left->left = btree_create_node("1");
    root->left->left->left->left->left->left->left = btree_create_node("0");
    printf("tree deep: %d\n", btree_level_count(root));
    root->right->left->right->right = btree_create_node("45");
    root->right->left->right->right->right = btree_create_node("49");
    root->right->left->right->right->right->left = btree_create_node("46");
    root->right->left->right->right->right->left->right = btree_create_node("48");
    root->right->left->right->right->right->left->right->left = btree_create_node("47");
    printf("tree deep: %d\n", btree_level_count(root));
    return (0);
}