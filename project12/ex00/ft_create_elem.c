//HEADER

#include "ft_list.h"

t_list  *ft_create_elem(void *data)
{
  t_list  *elem;

  elem = NULL;
  elem = (t_list *) malloc(sizeof(t_list));
  if (elem == NULL)
  {
    free(elem);
    return (NULL);
  }
  elem->data = data;
  elem->next = NULL;
  return (elem);
}
