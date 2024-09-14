//HEADER

#include "ft_list.h"

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
  t_list  *current;

  while (current != NULL)
  {
    if ((*cmp)(current->data, data_ref) == 0)
      return (current);
    current = current->next;
  }
  return (NULL);
}
