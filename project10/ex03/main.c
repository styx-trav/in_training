//HEADER

#include "lib.h"

void  error_msg(char *argv, int err)
{
  int j;
  char  *str;

  write(1, "ft_hexdump: ", 12);
  j = 0;
  while (argv[j])
  {
    write(1, &argv[j], 1);
    j++;
  }
  write(1, ": ", 2);
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

int second(int argc, char **argv, char *buf, int *ct)
{
  int j;
  int fd;

  j = 2;
  while (j < argc)
  {
    fd = open(argv[j], O_RDONLY);
    if (fd == -1)
      error_msg(argv[j], errno);
    else
    {
      if (reading_func(fd, buf, ct) == -1)
        return (-1);
    }
    j++;
  }
  return (0);
}

int main(int argc, char **argv)
{
  char  *buf;
  int ct;

  ct = 0;
  buf = create_buf();
  if (!buf)
    return (0);
  if(argc == 2)
  {
    if(reading_func(1, buf, &ct) == -1)
      return (0);
  }
  if (second(argc, argv, buf, &ct) == -1)
    return (0);
  if (buf[0] != '\0')
  {
    if (between_func(buf, &ct) == -1)
      return (0);
  }
  free(buf);
  return (0);
}
