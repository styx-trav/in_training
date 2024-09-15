//HEADER

#include <stdlib.h>
#include <stdio.h>

typedef struct  s_btree
{
  struct s_btree  *left;
  struct s_btree  *right;
  char            *item;
}               t_btree;

t_btree *btree_create_node(void *item)
{
  t_btree *new_thing;

  new_thing = (t_btree *) malloc(sizeof(t_btree));
  if (!new_thing)
  {
    free(new_thing);
    return (NULL);
  }
  new_thing->item = item;
  return (new_thing);
}

void  applyf(char *str)
{
  str[2] = 'z';
}

void  free_tree(t_btree *root)
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    free_tree(current->right);
    free_tree(current->left);
    free (current);
  }
}

void  btree_apply_prefix(t_btree *root, void (*applyf)(char *))
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    (*applyf)(current->item);
    btree_apply_prefix(current->right, applyf);
    btree_apply_prefix(current->left, applyf);
  }
}

void  disp_tree(t_btree *root)
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    printf("here string: %s,\n", current->item);
    disp_tree(current->right);
    disp_tree(current->left);
  }
}

int main(int argc, char **argv)
{
  t_btree *head;
  t_btree *tmp1;
  t_btree *tmp2;

  head = btree_create_node(argv[1]);
  head->left = NULL;
  head->right = NULL;
  tmp1 = head;
  head = btree_create_node(argv[2]);
  head->left = NULL;
  head->right = NULL;
  tmp2 = head;
  head = btree_create_node(argv[3]);
  head->left = tmp1;
  head->right = tmp2;
  tmp1 = head;
  head = btree_create_node(argv[4]);
  head->left = NULL;
  head->right = tmp1;
  tmp2 = head;
  head = btree_create_node(argv[5]);
  head->left = tmp2;
  head->right = NULL;
  disp_tree(head);
  btree_apply_prefix(head, &applyf);
  disp_tree(head);
  free_tree(head);
}
