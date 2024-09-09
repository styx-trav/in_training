//HEADER

#ifndef LIB_H
# define LIB_H "lib.h"

# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <libgen.h>
# include <stdlib.h>

//a structure specifically for the conversion function in main.c
struct ints
{
  int cat;
  unsigned int  num;
};

//and a structure specifically made for the permanent ints
struct perma_ints
{
  int argc;
  unsigned int  num;
};

//errors from errors.c
void  error_msg2(char *num_str);
void  error_msg(char *argv, int err);

//+num option from cat_prot.c
void find_cat(struct perma_ints s, char **argv);

//common functions from common.c
void  disp_name(char *argv, int argc, int fd);
void  empty_str(char *str, char *str2, unsigned int num);

//num option from tail_prot.c
void tail_prot(struct perma_ints s, char **argv, unsigned int j);

#endif
