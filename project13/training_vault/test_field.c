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
  new_thing->left = NULL;
  new_thing->right = NULL;
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
    btree_apply_prefix(current->left, applyf);
    btree_apply_prefix(current->right, applyf);
  }
}

void  disp_tree_preorder(t_btree *root)
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    printf("here string: %s,\n", current->item);
    disp_tree_preorder(current->left);
    disp_tree_preorder(current->right);
  }
}

void  disp_tree_inorder(t_btree *root)
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    disp_tree_inorder(current->left);
    printf("here string: %s,\n", current->item);
    disp_tree_inorder(current->right);
  }
}

void  disp_tree_postorder(t_btree *root)
{
  t_btree *current;

  current = root;
  if (current != NULL)
  {
    disp_tree_postorder(current->left);
    disp_tree_postorder(current->right);
    printf("here string: %s,\n", current->item);
  }
}

void  disp_tree_bylevel(t_btree *root, int i, int lev)
{
  t_btree *current;

  current = root;
  if (i == lev && current != NULL)
  {
    printf("here string: %s,\n", current->item);
    return ;
  }
  if (current != NULL)
  {
    disp_tree_bylevel(current->left, i + 1, lev);
    disp_tree_bylevel(current->right, i + 1, lev);
  }
}

int  disp_tree_bylevel_n2(t_btree *root, int i, int lev, int first)
{
  t_btree *current;

  current = root;
  if (root == NULL)
    return (first);
  if (i == lev)
  {
    if (first == 1)
    {
      printf("first of its level %d, ", lev);
      first = 0;
    }
    printf("here string: %s,\n", current->item);
  }
  if (i < lev)
  {
    first = disp_tree_bylevel_n2(current->left, i + 1, lev, first);
    first = disp_tree_bylevel_n2(current->right, i + 1, lev, first);
  }
  return (first);
}

t_btree **add_level(t_btree *root, int i, int lev, t_btree **previous, t_btree **first)
{
  t_btree *current;
  t_btree *tmp;

  current = root;
  if (root == NULL)
    return (previous);
  if (i == lev)
  {
    tmp = btree_create_node(current->item);
    if (first == previous)
      (*previous)->right = tmp;
    else
      (*previous)->left = tmp;
    previous = &tmp;
  }
  if (i < lev)
  {
    previous = add_level(current->left, i + 1, lev, previous, first);
    previous = add_level(current->right, i + 1, lev, previous, first);
  }
  return (previous);
}

void  disp_level_chain(t_btree  *head)
{
  t_btree *current;
  int i;

  current = head;
  i = 1;
  printf("root node, ");
  while (current != NULL)
  {
    printf("here string: %s,\n", current->item);
    if (current->right != NULL)
    {
      printf("first of its level %d, ", i);
      i++;
      current = current->right;
    }
    else
      current = current->left;
  }
}

void  create_level_chain(t_btree *root, int depth)
{
  t_btree *head;
  t_btree *current;
  t_btree *tmp;
  int i;

  i = 1;
  head = btree_create_node(root->item);
  if (root == NULL)
    return ;
  current = head;
  while (i < depth)
  {
    if (current->left == NULL && current->right == NULL)
    {
      tmp = (*add_level(root, 0, i, &current, &current));
      i++;
      if (tmp != NULL)
        printf("here our lost one : %s\n", tmp->item);
      free(tmp);
      disp_level_chain(head);
      free_tree(head);
      return ;
    }
    else if (current->left == NULL)
      current = current->right;
    else
      current = current->left;
  }
  disp_level_chain(head);
  free_tree(head);
}

int tree_depth(t_btree  *root, int lev)
{
  int lev1;
  int lev2;

  if (root != NULL)
  {
    lev1 = tree_depth(root->left, lev + 1);
    lev2 = tree_depth(root->right, lev + 1);
    if (lev1 < lev2)
      return (lev2);
    else
      return (lev1);
  }
  return (lev);
}

void  disp_tree_levels(t_btree *root, int depth)
{
  int i;

  i = 0;
  while (i < depth)
  {
    disp_tree_bylevel(root, 0, i);
    i++;
  }
}

void  disp_tree_levels_n2(t_btree *root, int depth)
{
  int i;

  i = 1;
  if (root == NULL)
    return ;
  printf("first of its level and root node, here string: %s,\n", root->item);
  while (i < depth)
  {
    if (disp_tree_bylevel_n2(root, 0, i, 1) == 1)
      printf("none found here at level %d\n", i);
    i++;
  }
}

int main(int argc, char **argv)
{
  t_btree *head;
  t_btree *tmp1;
  t_btree *tmp2;

  head = btree_create_node(argv[1]);
  head->left = btree_create_node(argv[2]);
  head->right = btree_create_node(argv[3]);
  head->left->right = btree_create_node(argv[4]);
  head->right->left = btree_create_node(argv[5]);
  head->right->right = btree_create_node(argv[6]);
  head->left->left = btree_create_node(argv[7]);
  head->left->left->right = btree_create_node(argv[8]);
  head->right->left->left = btree_create_node(argv[9]);
  head->right->left->right = btree_create_node(argv[10]);
  head->right->left->right->left = btree_create_node(argv[11]);
  disp_tree_preorder(head);
  //btree_apply_prefix(head, &applyf);
  printf("\n");
  disp_tree_inorder(head);
  printf("\n");
  disp_tree_postorder(head);
  printf("\nin levels: 0-%d\n", tree_depth(head, 0));
  disp_tree_levels(head, tree_depth(head, 0));
  printf("\n");
  disp_tree_levels_n2(head, tree_depth(head, 0));
  printf("\n");
  //create_level_chain(head, tree_depth(head, 0));
  free_tree(head);
}
