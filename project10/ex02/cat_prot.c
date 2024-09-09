//HEADER

#include "lib.h"

void  cat_read(int fd, unsigned int num)
{
  unsigned int  i;
  char  buf[2];

  i = 0;
  while (i < num - 1 && read(fd, buf, 1) != 0)
    i++;
  while (read(fd, buf, 1) != 0)
    write(1, &buf[0], 1);
}

int reading_file(struct perma_ints s, char *argv, unsigned int  j, int err)
{
  int fd;

  fd = open(argv, O_RDONLY);
  if (fd != -1)
  {
    if (j > 3 && !err)
      write(1, "\n\n", 2);
    err = 0;
    disp_name(argv, s.argc, fd);
    cat_read(fd, s.num);
    close(fd);
  }
  else
  {
    err = 1;
    error_msg(argv, errno);
  }
  return (err);
}

void find_cat(struct perma_ints s, char **argv)
{
  unsigned int j;
  int err;

  j = 3;
  err = 0;
  while ((int)j < s.argc)
  {
    if(argv[j][0] == '-' && !argv[j][1])
    {
      if (j > 3 && !err)
        write(1, "\n\n", 2);
      err = 0;
      disp_name(argv[j], s.argc, 1);
      cat_read(1, s.num);
    }
    else
      err = reading_file(s, argv[j], j, err);
    j++;
  }
}
