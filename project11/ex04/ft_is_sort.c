//HEADER

int ft_sort(int *tab, int length, int(*f)(int, int))
{
  int i;

  i = 1;
  while (i < length)
  {
    if (f(tab[i - 1], tab[i]) < 0)
      return (0);
    i++;
  }
  return (1);
}
