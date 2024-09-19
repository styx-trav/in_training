//HEADER

#include "ft_btree.h"

void  *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
  t_btree *current;
  void *tmp;

  if (root == NULL)
    return (NULL);
  current = root;
  tmp = btree_search_item(current->left, data_ref, cmpf);
  if (tmp != NULL)
    return (tmp);
  if ((*cmpf)(data_ref, current->item) == 0)
    return (current->item);
  return (btree_search_item(current->right, data_ref, cmpf));
}
