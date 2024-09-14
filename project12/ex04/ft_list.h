//HEADER

#ifndef FT_LIST_H
# define FT_LIST_H "ft_list.h"

# include <stdlib.h>
typedef struct  s_list
{
  struct s_list *next;
  void  *data;
}               t_list;

//from ../ex00/ft_create_elem.c, create_elem of list function
t_list  *ft_create_elem(void *data);

#endif
