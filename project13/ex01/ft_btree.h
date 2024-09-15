//HEADER

#ifndef FT_BTREE
# define FT_BTREE "ft_btree.h"

# include <stdlib.h>

typedef struct  s_btree
{
  struct s_btree  *left;
  struct s_btree  *right;
  void            *item;
}               t_btree;

//from btree_create_node.c, create tree node :
t_btree *btree_create_node(void *item);

#endif
