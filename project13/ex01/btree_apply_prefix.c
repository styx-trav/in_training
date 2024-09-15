//HEADER

#include "ft_btree.h"

void  btree_apply_prefix(t_btree *root, void (*applyf)(char *))
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    (*applyf)(current->item);
    btree_apply_prefix(current->left, applyf);
    btree_apply_prefix(current->right, applyf);
  }
}
