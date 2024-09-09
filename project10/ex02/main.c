//HEADER

#include "lib.h"

struct ints converting(char *num_str, struct ints given)
{
  int i;

  i = 0;
  if (num_str[i] == '+')
  {
    given.cat = 1;
    i++;
  }
  while (num_str[i])
  {
    if (num_str[i] < 48 || num_str[i] > 57
      || (given.num > 429496729 && num_str[i + 1])
      || (given.num == 429496729 && num_str[i + 1] > 1))
    {
      error_msg2(num_str);
      given.cat = -1;
      return (given);
    }
    given.num = given.num * 10 + num_str[i] - 48;
    i++;
  }
  return (given);
}

int main(int argc, char **argv)
{
  struct ints given;
  struct perma_ints s;

  given.cat = 0;
  given.num = 0;
  given = converting(argv[2], given);
  //this is where the branch-off would be, ideally : we'd want a
  //if num = 0, return;
  s.num = given.num;
  s.argc = argc;
  if (given.num == 0 || given.cat == -1)
    return (0);
  //if +num
  if (given.cat == 1)
    find_cat(s, argv);
  //if num
  if (!given.cat)
    tail_prot(s, argv, 3);
  return (0);
}
