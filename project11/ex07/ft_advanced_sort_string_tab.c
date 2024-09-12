//HEADER

void  ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
  int i;
  char  *buf;

  i = 1;
  while (str[i] != NULL)
  {
    if (cmp(str[i - 1], str[i]) < 0)
    {
      buf = str[i - 1];
      str[i - 1] = str[i];
      str[i] = buf;
      i = 0;
    }
    i++;
  }
}
