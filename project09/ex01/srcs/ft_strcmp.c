int ft_strcmp(char *s1, char *s2)
{
  int i;

  i = 0;
  while (s1[i] && s1[i] == s2[i])
    i++;
  if (s1[i] - s2[i] < 0)
    return (-1);
  if (s1[i] - s2[i] == 0)
    return (0);
  return (1);
}
