//HEADER

#include "lib.h"

void  write_zeroes(int num)
{
  int i;

  i = 0;
  while (i < 7 - num - 1)
  {
    write(1, "0", 1);
    i++;
  }
}

int find_str_len(int  ct)
{
  int num;

  num = 1;
  while (ct > 15)
  {
    ct = ct / 16;
    num++;
  }
  return (num);
}

char  *fill_str(int ct, char *str, char *base)
{
  int i;

  i = 0;
  while (ct > 15)
  {
    str[i] = base[ct % 16];
    i++;
    ct = ct / 16;
  }
  str[i] = base[ct % 16];
  str[i + 1] = '\0';
  return (str);
}

void disp_str(char *str, int num)
{
  int i;

  i = num;
  while (i >= 0)
  {
    write(1, &str[i], 1);
    i--;
  }
}

void  disp_lines(int *ct)
{
  char  *base;
  int num;
  char  *str;

  base = malloc(sizeof(char) * 17);
  if (!base)
  {
    free(base);
    return ;
  }
  base = fill_base(base);
  num = find_str_len(*ct);
  str = malloc(sizeof(char) * num + 1);
  if (!str)
  {
    free(str);
    return ;
  }
  str = fill_str(*ct, str, base);
  write_zeroes(num);
  disp_str(str, num);
  write(1, "0  ", 3);
  *ct = *ct + 1;
  free(str);
  free(base);
}
