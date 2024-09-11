//HEADER

void  ft_foreach(char *tab, int length, void(*f)(int))
{
  int  i;

  i = 0;
  while (i < length)
  {
    f(tab[i]);
    i++;
  }
}
