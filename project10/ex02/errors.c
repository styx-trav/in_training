//HEADER

#include "lib.h"

void  error_msg2(char *num_str)
{
  int i;

  i = 0;
  write(1, "ft_tail: invalid number of bytes: '", 36);
  while (num_str[i])
  {
    write(1, &num_str[i], 1);
    i++;
  }
  write(1, "'\n", 2);
}

void  error_msg(char *argv, int err)
{
  int j;
  char  *str;

  write(1, "ft_tail: cannot open '", 22);
  j = 0;
  while (argv[j])
  {
    write(1, &argv[j], 1);
    j++;
  }
  write(1, "' for reading : ", 16);
  j = 0;
  str = strerror(err);
  while (str[j])
  {
    write(1, &str[j], 1);
    j++;
  }
  write(1, "\n", 1);
  return ;
}

