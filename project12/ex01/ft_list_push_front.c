//HEADER

#include "ft_list.h"

void  ft_list_push_front(t_list **begin_list, void *data)
{
  t_list  *new_head;

  new_head = NULL;
  new_head = ft_create_elem(data);
  if (new_head == NULL)
    return ;
  new_head->next = *begin_list;
  *begin_list = new_head;
}
