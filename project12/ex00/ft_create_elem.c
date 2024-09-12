//HEADER

#include "ft_list.h"

t_list  *ft_create_elem(void *data)
{
  t_list  elem;

  t_list.data = data;
  t_list.next = NULL;
  return (&elem);
}
