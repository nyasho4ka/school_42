#include <unistd.h>
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

void btree_apply_infix(t_btree* root, void(*applyf)(void*))
{
    if (root == (void*)(0))
        return;
    
    btree_apply_infix(root->left, applyf);
    (*applyf)(root->item);
    btree_apply_infix(root->right, applyf);
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

    btree_apply_infix(root, &ft_putstr);

    return (0);
}