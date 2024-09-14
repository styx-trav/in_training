#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void  disp_list(node_t **head)
{
  node_t  *current;

  current = *head;
  while (current->next != NULL)
  {
    printf(":%d\n", current->val);
    current = current->next;
  }
  printf(":%d\n\n", current->val);
}

void  free_list(node_t **head)
{
  node_t  *current;
  node_t  *tmp;

  current = *head;
  while (current->next != NULL)
  {
    tmp = current->next;
    free(current);
    current = tmp;
  }
  free(current);
}

void  add_head(node_t **head, int val)
{
  node_t *new_head = NULL;

  new_head = (node_t *) malloc(sizeof(node_t));
  if (new_head == NULL)
      return ;
  new_head->next = *head;
  new_head->val = val;
  *head = new_head;
}

void  add_tail(node_t **head, int val)
{
  node_t  *new_tail = NULL;
  node_t  *current;

  new_tail = (node_t *) malloc(sizeof(node_t));
  if (new_tail == NULL)
    return ;
  new_tail->next = NULL;
  new_tail->val = val;
  current = *head;
  if (current->next == NULL)
  {
    add_head(head, val);
    return ;
  }
  while (current->next != NULL)
    current = current->next;
  current->next = new_tail;
}

void  add_item_by_value(node_t **head, int value, int val)
{
  node_t  *new_item = NULL;
  node_t  *current;

  current = *head;
  if (current == NULL)
    return ;
  while (current->val != value)
  {
    current = current->next;
    if (current == NULL)
      return ;
  }
  new_item = (node_t *) malloc(sizeof(node_t));
  if (new_item == NULL)
    return ;
  new_item->next = current->next;
  new_item->val = val;
  current->next = new_item;
}

void  add_item_by_index(node_t **head, int index, int val)
{
  node_t  *new_item = NULL;
  node_t  *current;
  int ind;

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
  new_item = (node_t *) malloc(sizeof(node_t));
  if (new_item == NULL)
    return ;
  new_item->next = current->next;
  new_item->val = val;
  current->next = new_item;
}

int  delete_head(node_t **head)
{
  node_t  *tmp;
  int val;

  if (*head == NULL)
    return (-1);
  tmp = (*head)->next;
  val = (*head)->val;
  free(*head);
  *head = tmp;
  return (val);
}

void  delete_tail(node_t **head)
{
  node_t  *current;

  if (*head == NULL)
    return ;
  if ((*head)->next == NULL)
  {
    delete_head(head);
    return ;
  }
  current = *head;
  while (current->next->next != NULL)
    current = current->next;
  free(current->next);
  current->next = NULL;
}

int  delete_item_by_index(node_t **head, int index)
{
  node_t  *current;
  node_t  *tmp;
  int ind;
  int val;

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

void  delete_item_by_value(node_t **head, int value)
{
  node_t  *current;
  node_t  *tmp;

  current = *head;
  if (current->val == value)
  {
    delete_head(head);
    return ;
  }
  if (current->next == NULL)
    return ;
  while (current->next->val != value)
  {
    current = current->next;
    if (current->next == NULL)
      return ;
  }
  tmp = current->next->next;
  free(current->next);
  current->next = tmp;
}

void  replace_head(node_t **head, int val)
{
  delete_head(head);
  add_head(head, val);
}

void  replace_tail(node_t **head, int val)
{
  delete_tail(head);
  add_tail(head, val);
}

void  replace_item_by_value(node_t **head, int value, int val)
{
  add_item_by_value(head, value, val);
  delete_item_by_value(head, value);
}

void  replace_item_by_index(node_t **head, int index, int val)
{
  delete_item_by_index(head, index);
  add_item_by_index(head, index, val);
}

void  switch_items(node_t **head, int ind1, int ind2)
{
  int val1;
  int val2;

  if (ind1 == ind2)
    return ;
  if (ind2 < ind1)
  {
    val1 = delete_item_by_index(head, ind1);
    if (val1 == -1)
      return ;
    val2 = delete_item_by_index(head, ind2);
    if (val2 == -1)
      return ;
    add_item_by_index(head, ind2, val1);
    add_item_by_index(head, ind1, val2);
  }
  else
  {
    val2 = delete_item_by_index(head, ind2);
    if (val2 == -1)
      return ;
    val1 = delete_item_by_index(head, ind1);
    if (val1 == -1)
      return ;
    add_item_by_index(head, ind1, val2);
    add_item_by_index(head, ind2, val1);
  }
}

void  reverse_list(node_t **head)
{
  int len;
  int i;
  node_t  *current;

  len = 0;
  current = *head;
  while (current != NULL)
  {
    len++;
    current = current->next;
  }
  i = 0;
  while (i < len / 2)
  {
    switch_items(head, i, len - i - 1);
    i++;
  }
}

int main(void)
{
  node_t *head = NULL;
  head = (node_t *) malloc(sizeof(node_t));
  if (head == NULL) {
      return (1);
  }
  head->val = 1;
  head->next = NULL;
  add_head(&head, 6);
  disp_list(&head);
  add_tail(&head, 13);
  disp_list(&head);
  add_item_by_value(&head, 6, 7);
  disp_list(&head);
  add_item_by_index(&head, 3, 16);
  disp_list(&head);
  replace_item_by_value(&head, 6, 4);
  disp_list(&head);
  replace_item_by_index(&head, 2, 9);
  disp_list(&head);
  switch_items(&head, 0, 3);
  disp_list(&head);
  add_item_by_index(&head, 3, 47);
  disp_list(&head);
  reverse_list(&head);
  disp_list(&head);
  free_list(&head);
  return (0);
}
