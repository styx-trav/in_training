//HEADER

//goal: sort a tab of strings in ascii order
//i'm assuming tab is null-terminated ?
#include <stdlib.h>
#include <stdio.h>

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

int main(int argc, char **argv)
{
  int i;

  argv[argc] = NULL;
  ft_sort_string_tab(argv);
  i = 0;
  while (i < argc)
  {
    printf("string n°%d: %s\n", i, argv[i]);
    i++;
  }
  return (0);
}
