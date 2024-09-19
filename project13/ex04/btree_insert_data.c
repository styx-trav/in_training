//HEADER

#include "ft_btree.h"

void  btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
  t_btree *current;

  if (*root == NULL)
  {
    *root = btree_create_node(item);
    return ;
  }
  current = *root;
  if ((*cmpf)(current->item, item) < 0)
  {
    if (current->left == NULL)
    {
      current->left = btree_create_node(item);
      return ;
    }
    else
      btree_insert_data(&current->left, item, cmpf);
  }
  else
  {
    if (current->right == NULL)
    {
      current->right = btree_create_node(item);
      return ;
    }
    else
      btree_insert_data(&current->right, item, cmpf);
  }
}
