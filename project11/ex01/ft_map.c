//HEADER

#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
  int i;
  int *new_tab;

  i = 0;
  new_tab = malloc(sizeof(int) * length);
  if (!new_tab)
  {
    free(new_tab);
    return (NULL);
  }
  while (i < length)
  {
    new_tab[i] = f(tab[i]);
    i++;
  }
  return (new_tab);
}
