//remplacer node_t par le nom de la structure
#include <stdlib.h>

typedef struct node_struct
{
  char  *data;
  struct node_struct  *next;
}   node;

void  free_list(node **head)
{
  node  *current;
  node  *tmp;

  current = *head;
  while (current->next != NULL)
  {
    tmp = current->next;
    free(current);
    current = tmp;
  }
  free(current);
}
