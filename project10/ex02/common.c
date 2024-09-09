//HEADER

#include "lib.h"

void  empty_str(char *str, char *str2, unsigned int num)
{
  unsigned int i;

  i = 0;
  while (i <= num)
  {
    str[i] = '\0';
    str2[i] = '\0';
    i++;
  }
}

void  disp_name(char *argv, int argc, int fd)
{
  int i;

  if (argc > 4)
  {
    write(1, "==> ", 4);
    i = 0;
    if (fd == 1)
      write(1, "standard input", 14);
    else
    {
      while (argv[i])
      {
        write(1, &argv[i], 1);
        i++;
      }
    }
    write(1, " <==\n", 5);
  }
}
