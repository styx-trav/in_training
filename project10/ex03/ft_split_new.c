//HEADER

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void  freeprot(char **tab, int  ct)
{
  int a;

  a = 0;
  while (a < ct)
  {
    free(tab[a]);
    a++;
  }
  free(tab);
}

int str_len(char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int count_tab(char *str, char *charset, int last_sep, char **tab)
{
  int i;
  int j;
  int ct;

  i = last_sep;
  while (str[i])
  {
    j = 0;
    while (charset[j] && charset[j] == str[i + j])
      j++;
    if (charset[j] == '\0')
    {
      if (tab == NULL)
        return (ct);
    i++;
  }
}

char  **splitting(char *str, char *charset, char **tab)
{
  int i;
  int j;

  i = 0;
  while (str[i])
}

char  **ft_split(char *str, char *charset)
{
  char  **tab;

  tab = malloc(sizeof(char *) * count_tab(str, charset));
  if (!tab)
  {
    free(tab);
    return (NULL);
  }
  
}
