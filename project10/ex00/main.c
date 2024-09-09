//HEADER

#include <unistd.h>
#include <fcntl.h>

void display_file(char **argv, int argc)
{
   int i;
   int fd;
   char buf[2];

   i = 1;
   while (i < argc)
   {
    fd = open(argv[i], O_RDONLY);
    if (fd == -1)
    {
      write(2, "Cannot read file.\n", 18);
      i++;
      fd = open(argv[i], O_RDONLY);
    }
    while (read(fd, buf, 1) != 0)
    {
      write(1, buf, 1);
    }
    close(fd);
    i++;
  }
}

int main(int argc, char **argv)
{
  if (argc == 1)
  {
    write(2, "File name missing.\n", 19);
    return (0);
  }
  if (argc > 2147483647)
  {
    write(2, "Too many arguments.\n", 21);
    return (0);
  }
  display_file(argv, argc);
  return (0);
}
