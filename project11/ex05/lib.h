//HEADER

#ifndef LIB_H
# define LIB_H "lib.h"

# include <unistd.h>
# include <stdlib.h>

//from op_func.c, all operator functions
int sum(int a, int b);
int divide(int a, int b);
int modul(int a, int b);
int subs(int a, int b);
int mult(int a, int b);

//from disp_num.c, the disp function
int disp_num(int num);
#endif
