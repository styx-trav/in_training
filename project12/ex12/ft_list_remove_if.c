//HEADER

#include "ft_list.c"

void  delete_head(node_t **head)
{
  t_list  *tmp;

  if (*head == NULL)
    return ;
  tmp = (*head)->next;
  val = (*head)->val;
  free(*head);
  *head = tmp;
}

void  delete_by_index(t_list **head, int index)
{
  int i;
  t_list  *current;
  t_list  *tmp;

  if (index == 0)
  {
    delete_head(head);
    return ;
  }
  current = *head;
  ind = 1;
  while (ind < index)
  {
    current = current->next;
    if (current->next == NULL)
      return (-1);
    ind++;
  }
  tmp = current->next->next;
  free(current->next);
  current->next = tmp;
}

void  ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
  int i;
  t_list  *current;

  i = 0;
  current = *begin_list;
  while (current != NULL)
  {
    if((*cmp)(current->data, data_ref) == 0)
    {
      delete_by_index(begin_list, i);
      i--;
    }
    i++;
    current = current->next;
  }
}
