//HEADER

int ft_count_if(char **tab, int length, int(*f)(char*))
{
  int i;
  int ct;

  i = 0;
  ct = 0;
  while (i < length)
  {
    if (f(tab[i]) != 0)
      ct++;
    i++;
  }
  return (ct);
}
