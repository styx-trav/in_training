//HEADER

#include <stdlib.h>

void  ft_sort_string_tab(char **tab)
{
  int i;
  int j;
  char  *buf;

  i = 1;
  while (tab[i] != NULL)
  {
    j = 0;
    while (tab[i - 1][j] && tab[i - 1][j] == tab[i][j])
      j++;
    if (tab[i - 1][j] > tab[i][j])
    {
      buf = tab[i - 1];
      tab[i - 1] = tab[i];
      tab[i] = buf;
      i = 0;
    }
    i++;
  }
}
