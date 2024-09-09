CC=gcc
CCFLAGS=-Wall -Wextra -Werror
NAME=ft_tail
SRCS=tail_prot.c main.c cat_prot.c errors.c common.c
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
