//HEADER

#include "ft_list.h"
#include <stdio.h>

void  free_prot(t_list **head)
{
  t_list  *current;
  t_list  *tmp;

  current = *head;
  while (current->next != NULL)
  {
    tmp = current->next;
    free(current);
    current = tmp;
  }
  free(current);
}

t_list  *ft_list_push_strs(int size, char **strs)
{
  t_list  *current;
  t_list  *tmp;
  int i;

  i = 0;
  tmp = NULL;
  while (i < size)
  {
    current = ft_create_elem((void *)strs[i]);
    if (current == NULL)
    {
      free_prot(&current);
      return (NULL);
    }
    if (tmp != NULL)
      current->next = tmp;
    tmp = current;
    i++;
  }
  return (current);
}
