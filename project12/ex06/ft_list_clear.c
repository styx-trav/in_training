//HEADER

#include "ft_list.h"

void  ft_list_clear(t_list *begin_list, void(*free_fct)(void *))
{
  t_list  *current;
  t_list  *tmp;

  current = begin_list;
  while (current != NULL)
  {
    free_fct(current->data);
    tmp = current->next;
    free(current);
    current = tmp;
  }
}
