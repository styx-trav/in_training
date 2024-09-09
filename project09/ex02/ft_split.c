// HEADER HERE

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

int findct(char *str, char *charset)
{
  int i;
  int j;
  int lastsepend;
  int ct;

  i = 0;
  lastsepend = 0;
  ct = 0;
  while (str[i])
  {
    j = 0;
    while (str[i + j] && str[i + j] == charset[j])
      j++;
    if (!charset[j])
    {
      if (i != lastsepend)
        ct++;
      lastsepend = i + j;
      i = lastsepend - 1;
    }
    i++;
    if (!str[i] && i != lastsepend)
      ct++;
  }
  return (ct);
}

char  **through_tab(char *str, char *charset, char **tab)
{
  int i;
  int j;
  int a;
  int lastsepend;
  int ct;

  i = 0;
  lastsepend = 0;
  ct = 0;
  while (str[i])
  {
    j = 0;
    while (str[i + j] && charset[j] == str[i + j])
      j++;
    if (!charset[j])
    {
      if (i != lastsepend)
      {
        tab[ct] = malloc(sizeof(char) * (i - lastsepend + 1));
        if (!tab[ct])
        {
          freeprot(tab, ct);
          return (NULL);
        }
        a = 0;
        while (lastsepend + a < i)
        {
          tab[ct][a] = str[a + lastsepend];
          a++;
        }
       tab[ct][a] = '\0';
        ct++;
      }
      lastsepend = i + j;
      i = lastsepend - 1;
    }
    i++;
  }
  return (tab);
}

char  **ft_split(char *str, char *charset)
{
  int a;
  int ct;
  char  **tab;

  tab = NULL;
  ct = findct(str, charset);
  tab = malloc(sizeof(char*) * ct);
  if (!tab)
  {
    free(tab);
    return (NULL);
  }
  tab = through_tab(str, charset, tab);
  a = 0;
  while (a < ct)
  {
    printf("here string number %d : %s\n", a, tab[a]);
    a++;
  }
  freeprot(tab, ct);
  return (NULL);
}

int main()
{
  char  **str;
  
  str = ft_split(", , here a ,,  bunch, ", ", ");
}

//fixed for perfectionism reasons : only changes needed are the last function cut that was walked back
//checked and valgrinded, no leaks no errors
