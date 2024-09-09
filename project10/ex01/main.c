//HEADER

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>

void  the_read_func(int fd)
{
  char  buf[2];

  while (read(fd, buf, 1) != 0)
  {
    write(1, buf, 1);
  }
  return ;
}

void  error_msg(char *argv, int err)
{
  int j;
  char  *str;

  write(1, "ft_cat: ", 8);
  str = basename(argv);
  j = 0;
  while (str[j])
  {
    write(1, &str[j], 1);
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

int main(int argc, char **argv)
{
  int i;
  int fd;

  i = 1;
  if (argc == 1)
    the_read_func(1);
  while (i < argc)
  {
    if (argv[i][0] == '-' && !argv[i][1])
      the_read_func(1);
    else
    {
      fd = open(argv[i], O_RDONLY);
       if (fd == -1)
         error_msg(argv[i], errno);
       else
       {
         the_read_func(fd);
         close(fd);
       }
    }
    i++;
  }
}
