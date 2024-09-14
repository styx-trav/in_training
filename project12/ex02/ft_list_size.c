//HEADER

#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
  int len;
  t_list  *current;

  len = 0;
  current = begin_list;
  while (current != NULL)
  {
    current = current->next;
    len++;
  }
  return (len);
}
