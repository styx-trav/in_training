//HEADER

#ifndef FT_BTREE
# define FT_BTREE "ft_btree.h"

# include <stdlib.h>

typedef struct  s_btree
{
  struct s_btree  *left;
  struct s_btree  *right;
  void            *item;
}               t_btree;

#endif
