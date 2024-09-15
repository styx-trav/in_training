//HEADER

#include "ft_list.h"

void  add_head(t_list **head, void *val)
{
  t_list *new_head;

  new_head = NULL;
  new_head = create_elem(val);
  if (new_head == NULL)
      return ;
  new_head->next = *head;
  *head = new_head;
}

void  add_item_by_index(t_list **head, int index, void *val)
{
  t_list  *new_item;
  t_list  *current;
  int ind;

  new_item = NULL;
  current = *head;
  if (index == 0)
  {
    add_head(head, val);
    return ;
  }
  ind = 0;
  while (ind < index - 1)
  {
    if (current == NULL)
      return ;
    current = current->next;
    ind++;
  }
  new_item = create_elem(val);
  if (new_item == NULL)
    return ;
  new_item->next = current->next;
  current->next = new_item;
}

void  *delete_item_by_index(t_list **head, int index)
{
  t_list  *current;
  t_list  *tmp;
  int ind;
  void *val;

  if (index == 0)
    return (delete_head(head));
  current = *head;
  ind = 1;
  while (ind < index)
  {
    current = current->next;
    if (current->next == NULL)
      return (-1);
    ind++;
  }
  val = current->next->val;
  tmp = current->next->next;
  free(current->next);
  current->next = tmp;
  return (val);
}

void  switch_items(t_list **head, int ind1, int ind2)
{
  void *val1;
  void *val2;

  val2 = delete_item_by_index(head, ind2);
  if (val2 == -1)
    return ;
  val1 = delete_item_by_index(head, ind1);
  if (val1 == -1)
    return ;
  add_item_by_index(head, ind1, val2);
  add_item_by_index(head, ind2, val1);
}

void  ft_list_sort(t_list **begin_list)
{
  int i;
  t_list  *current;

  i = 0;
  current = *begin_list;
  while (current->next != NULL)
  {
    if ((*cmp)(current->data, current->next->data) > 0)
      switch_items(begin_list, i, i + 1);
    current = current->next;
    i++;
  }
}
