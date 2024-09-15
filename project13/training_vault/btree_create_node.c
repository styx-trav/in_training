//HEADER

#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
  t_btree *new_thing;

  new_thing = (t_btree *) malloc(sizeof(t_btree));
  if (!new_thing)
  {
    free(new_thing);
    return (NULL);
  }
  new_thing->item = item;
  return (new_thing);
}
