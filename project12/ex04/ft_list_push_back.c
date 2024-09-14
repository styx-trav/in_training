//HEADER

#include "ft_list.h"

void  add_head(t_list **head, void *val)
{
  node_t *new_head = NULL;

  new_head = create_elem(val);
  if (new_head == NULL)
    return ;
  new_head->next = *head;
  *head = new_head;
}

void  ft_list_push_back(t_list **begin_list, void *data)
{
  t_list  *new_tail = NULL;
  t_list  *current;

  new_tail = create_elem(data)
  if (new_tail == NULL)
    return ;
  current = *head;
  if (current->next == NULL)
  {
    add_head(begin_list, data);
    return ;
  }
  while (current->next != NULL)
    current = current->next;
  current->next = new_tail;
}
