//HEADER

#include "lib.h"

void  disp_tail(char *str, char *str2, unsigned int  found, unsigned int num)
{
  unsigned int j;

  j = found;
  while (j < num && str[j])
  {
    write(1, &str[j], 1);
    j++;
  }
  j = 0;
  while (j < found && str2[j])
  {
    write(1, &str2[j], 1);
    j++;
  }
  return ;
}

void  find_tail(char  *str, char *str2, int fd, unsigned int num)
{
  unsigned int found;
  int sw;

  found = read(fd, str, num);
  sw = 0;
  while (found == num)
   {
     if (!sw)
     {
       sw = 1;
       found = read(fd, str2, num);
     }
     else
     {
       sw = 0;
       found = read(fd, str, num);
     }
   }
   if (sw)
    disp_tail(str, str2, found, num);
  else
    disp_tail(str2, str, found, num);
}

int tail_file(struct perma_ints s, char **argv, unsigned int j, int err)
{
  char  *str;
  char  *str2;
  int fd;

  str = malloc(sizeof(char) * (s.num +1));
  str2 = malloc(sizeof(char) * (s.num +1));
  if (!str || !str2)
  {
    free(str);
    free(str2);
    return (1);
  }
  empty_str(str, str2, s.num);
  fd = open(argv[j], O_RDONLY);
  if (fd != -1)
  {
    if (j > 3 && !err)
      write(1, "\n\n", 2);
    err = 0;
    disp_name(argv[j], s.argc, fd);
    find_tail(str, str2, fd, s.num);
    close(fd);
  }
  else
  {
    err = 1;
    error_msg(argv[j], errno);
  }
  free(str);
  free(str2);
  return (err);
}

void tail_prot(struct perma_ints s, char **argv, unsigned int j)
{
  char  *str;
  char  *str2;
  int err;

  str = malloc(sizeof(char) * (s.num +1));
  str2 = malloc(sizeof(char) * (s.num +1));
  if (!str || !str2)
  {
    free(str);
    free(str2);
    return ;
  }
  empty_str(str, str2, s.num);
  if (s.argc == 3)
    find_tail(str, str2, 1, s.num);
  err = 0;
  while ((int)j < s.argc)
  {
    if(argv[j][0] == '-' && !argv[j][1])
    {
      if (j > 3 && !err)
        write(1, "\n\n", 2);
      err = 0;
      disp_name(argv[j], s.argc, 1);
      find_tail(str, str2, 1, s.num);
    }
    else
      err = tail_file(s, argv, j, err);
    j++;
  }
  free(str);
  free(str2);
}
