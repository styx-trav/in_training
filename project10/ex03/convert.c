//HEADER

#include "lib.h"

char  *fill_base(char *base)
{
  int i;
  char  a;

  i = 0;
  while (i < 10)
  {
    base[i] = i + 48;
    i++;
  }
  a = 'a';
  while (i < 16)
  {
    base[i] = a;
    i++;
    a++;
  }
  base[i] = '\0';
  return (base);
}

char  *int_to_hexdec(int num, char *base)
{
  char  *str;

  str = malloc(sizeof(char) * 3);
  if (!str)
  {
    free(str);
    return (NULL);
  }
  if (num < 16)
  {
    str[0] = '0';
    str[1] = base[num];
  }
  else
  {
    str[1] = base[num % 16];
    str[0] = base[num / 16];
  }
  str[2] = '\0';
  free(base);
  return (str);
}

char *call_conv(int num)
{
  char  *base;

  base = malloc(sizeof(char) * 17);
  if (!base)
  {
    free(base);
    return (NULL);
  }
  base = fill_base(base);
  return (int_to_hexdec(num, base));
}
