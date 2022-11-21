#include <stdlib.h>
#include "ft_tree.h"

t_btree* btree_create_node(void* item)
{
    t_btree* node = (t_btree*)malloc(sizeof(t_btree));
    if (node)
    {
        node->item = item;
        node->left = (void*)(0);
        node->right = (void*)(0);
    }
    return node;
}
