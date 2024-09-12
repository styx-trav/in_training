//HEADER

#include "lib.h"

int is_neg(int num)
{
  if (num < 0)
  {
    num = -num;
    write(1, "-", 1);
  }
  return (num);
}

int find_num_len(int num)
{
  int i;

  i = 1;
  while (num > 9)
  {
    i++;
    num = num / 10;
  }
  return (i);
}

void  disp_str(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    write(1, &str[i], 1);
    i++;
  }
  write(1, "\n", 1);
}

int disp_num(int num)
{
  char  *str;
  int len;

  num = is_neg(num);
  len = find_num_len(num);
  str = malloc(sizeof(char) * (len + 1));
  if (!str)
  {
    free(str);
    return (-1);
  }
  str[len] = '\0';
  while (num > 9)
  {
    len--;
    str[len] = (num % 10) + 48;
    num = num / 10;
  }
  str[0] = num + 48;
  disp_str(str);
  free(str);
  return (0);
}
