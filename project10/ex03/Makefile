CC=gcc
CCFLAGS=-Wall -Wextra -Werror
NAME=ft_hexdump
SRCS=main.c convert.c reading.c bufs.c disp_lines.c
HEADER=lib.h

$(NAME): $(SRCS) $(HEADER)
	$(CC) -o $(NAME) $(CCFLAGS) $(SRCS)

.PHONY: all clean fclean re

clean:
	rm $(NAME)

all: $(NAME) re

fclean:
	rm $(NAME)

re: clean $(NAME)
