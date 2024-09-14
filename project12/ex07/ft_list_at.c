//HEADER

#include "ft_list.h"

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
  unsigned int  i;
  t_list  *current;

  i = 0;
  current = begin_list;
  while (i < nbr)
  {
    current = current->next;
    if (current == NULL)
      return (NULL);
    i++;
  }
  return (current);
}
