//HEADER

#include "ft_list.h"

void  ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
  t_list  *current;

  if (*begin_list1 == NULL)
  {
    *begin_list1 = begin_list2;
    return ;
  }
  if ((*begin_list1)->next == NULL)
  {
    (*begin_list1)->next = begin_list2;
    return ;
  }
  current = *begin_list1;
  while (current->next != NULL)
    current = current->next;
  current = begin_list2;
}
