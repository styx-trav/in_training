//HEADER

#ifndef LIB_H
# define LIB_H "lib.h"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

//here the int to hex conversion func, from convert.c
char *call_conv(int num);
//making a base, also from convert.c
char  *fill_base(char *base);
//here the reading func, from reading.c, and her sister in-between calls
int  reading_func(int fd, char *buf, int *ct);
int between_func(char *buf, int *ct);
//here the creating of a 17 buffer and the emtpying of it from bufs.c
char  *create_buf(void);
char  *empty_buf(char *buf);
//the buf and buffer, for transition lines, from bufs.c
char  *buf_and_buffer(char *buf, char *buffer, int s);
//my disp_lines call, from disp_lines.c
void  disp_lines(int *ct);
#endif
