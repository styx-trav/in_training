//HEADER

#include "ft_btree.h"

void  btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    btree_apply_prefix(current->left, applyf);
    (*applyf)(current->item);
    btree_apply_prefix(current->right, applyf);
  }
}
