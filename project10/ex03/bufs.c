//HEADER

#include "lib.h"

char  *create_buf(void)
{
  int i;
  char  *buf;

  buf = malloc(sizeof(char) * 17);
  if (!buf)
  {
    free(buf);
    return (NULL);
  }
  i = 0;
  while (i < 17)
  {
    buf[i] = '\0';
    i++;
  }
  return (buf);
}

char  *empty_buf(char *buf)
{
  int i;

  i = 0;
  while (i < 17)
  {
    buf[i] = '\0';
    i++;
  }
  return (buf);
}

char  *buf_and_buffer(char *buf, char *buffer, int s)
{
  int j;

  j = 0;
  while (buffer[j] && j < 16 - s)
  {
    buf[s + j] = buffer[j];
    j++;
  }
  return (buf);
}


