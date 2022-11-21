#include <stdio.h>
#include "ft_tree.h"

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

void* btree_search_item(t_btree* root, void* data_ref, int(*cmp)(void*, void*))
{
    void* res = (void*)(0);
    if (root == (void*)(0))
        return res;

    res = btree_search_item(root->left, data_ref, cmp);
    if (res != (void*)(0))
        return res;

    if ((*cmp)(data_ref, root->item) == 0)
    {
        res = root->item;
    }
    if (res != (void*)(0))
        return res;

    res = btree_search_item(root->right, data_ref, cmp);
    return res;
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

    char* res; 
    res = btree_search_item(root, "66", &ft_strcmp);
    printf("res: %s\n", res);
    res = btree_search_item(root, "636", &ft_strcmp);
    printf("res: %s\n", res);
    res = btree_search_item(root, "5", &ft_strcmp);
    printf("res: %s\n", res);
    res = btree_search_item(root, "12", &ft_strcmp);
    printf("res: %s\n", res);

    return (0);
}