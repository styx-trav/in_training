//HEADER

#include "ft_btree.h"

int tree_depth(t_btree  *root, int lev)
{
  int lev1;
  int lev2;

  if (root != NULL)
  {
    lev1 = tree_depth(root->left, lev + 1);
    lev2 = tree_depth(root->right, lev + 1);
    if (lev1 < lev2)
      return (lev2);
    else
      return (lev1);
  }
  return (lev);
}

int btree_level_count(t_btree *root)
{
  return (tree_depth(root, 0));
}
