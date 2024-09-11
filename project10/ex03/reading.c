//HEADER

#include "lib.h"

int  disp_hex(char *buf, int j)
{
  char *a;

  a = call_conv((int) buf[j]);
  if (a == NULL)
    return (-1);
  write(1, &a[0], 1);
  write(1, &a[1], 1);
  write(1, " ", 1);
  free(a);
  j++;
  return (j);
}

void  disp_read(char *buf, int j)
{
  int i;

  i = 0;
  while (i < 16 - j)
  {
    write(1, "   ", 3);
    i++;
  }
  i = 0;
  write(1, " |", 2);
  while (buf [i])
  {
    if (buf[i] == '\n')
      write(1, ".", 1);
    else
      write(1, &buf[i], 1);
    i++;
  }
  write(1, "|\n", 2);
}

int between_func(char *buf, int *ct)
{
  int j;

  j = 0;
  if (buf[j])
    disp_lines(ct);
  while (buf[j] && j < 8)
  {
    j = disp_hex(buf, j);
    if (j == -1)
      return (-1);
  }
  write(1, " ", 1);
  while (buf[j])
  {
    j = disp_hex(buf, j);
    if (j == -1)
      return (-1);
  }
  disp_read(buf, j);
  return (0);
}

int transitional_read(int fd, char *buf, int *ct)
{
  int j;
  char *buffer;
  int s;

  j = 0;
  if (buf[j] != '\0')
  {
    buffer = create_buf();
    if (!buffer)
      return (-1);
    while (buf[j] != '\0')
      j++;
    if (j != 16)
    {
      s = read(fd, buffer, 16 - j);
      buf = buf_and_buffer(buf, buffer, j);
      free(buffer);
      if (s + j < 16)
        return (1);
    }
    else
      free(buffer);
    if (between_func(buf, ct) == -1)
      return (-1);
  }
  return (0);
}

int  reading_func(int fd, char *buf, int *ct)
{
  int s;

  s = transitional_read(fd, buf, ct);
  if (s == -1)
    return (-1);
  if (s == 1)
    return (0);
  buf = empty_buf(buf);
  s = read(fd, buf, 16);
  while (s == 16)
  {
    if (between_func(buf, ct) == -1)
      return (-1);
    buf = empty_buf(buf);
    s = read(fd, buf, 16);
  }
  return (0);
}
