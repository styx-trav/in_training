//HEADER

#include "lib.h"

void  disp_err(int  a)
{
  write(1, "Stop : ", 7);
  if (a == 3)
    write(1, "division ", 9);
  else
    write(1, "modulo ", 7);
  write(1, "by zero\n", 8);
}

int  atoi_type_sh(char *str)
{
  int i;
  int  num;
  int sign;

  i = 0;
  num = 0;
  sign = 1;
  if (str == "-2147483648")
    return (-2147483648);
  while (str[i] == '+' || str[i] == '-')
  {
    if (str[i] == '-')
      sign = sign * (-1);
    i++;
  }
  while (str[i])
  {
    if (str[i] < '0' || str[i] > '9')
      return (num * sign);
    num = num * 10 + str[i] - 48;
    i++;
  }
  return (num * sign);
}

int char_to_op(char *str)
{
  if (str[1] != '\0')
  {
    write(1, "0\n", 2);
    return (-1);
  }
  if (str[0] == '+')
    return (0);
  if (str[0] == '-')
    return (1);
  if (str[0] == '*')
    return (2);
  if (str[0] == '/')
    return (3);
  if (str[0] == '%')
    return (4);
  write(1, "0\n", 2);
  return (-1);
}

int main(int argc, char **argv)
{
  int (*p[5]) (int, int);
  int op;

  p[0] = sum;
  p[1] = subs;
  p[2] = mult;
  p[3] = divide;
  p[4] = modul;
  if (argc == 4)
  {
    op = char_to_op(argv[2]);
    if (op == -1)
      return (0);
    if ((op == 3 || op == 4)
      && (argv[3][0] == '0' && argv[3][1] == '\0'))
    {
      disp_err(op);
      return (0);
    }
    disp_num(p[op](atoi_type_sh(argv[1]), atoi_type_sh(argv[3])));
  }
  return (0);
}
