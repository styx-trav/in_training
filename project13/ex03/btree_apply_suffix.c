//HEADER

#include "ft_btree.h"

void  btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    btree_apply_prefix(current->left, applyf);
    btree_apply_prefix(current->right, applyf);
    (*applyf)(current->item);
  }
}
