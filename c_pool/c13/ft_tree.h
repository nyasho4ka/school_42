#ifndef __FT_TREE__
#define __FT_TREE__

typedef struct s_btree {
    struct s_btree  *left;
    struct s_btree  *right;
    void            *item;
}                   t_btree;

t_btree* btree_create_node(void* item);

#endif