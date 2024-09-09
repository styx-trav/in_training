CC=gcc
CCFLAGS=-Wall -Wextra -Werror
NAME=ft_cat

$(NAME): main.c
	$(CC) -o $(NAME) $(CCFLAGS) $^

.PHONY: all clean fclean re

clean:
	rm $(NAME)

all: $(NAME) re

fclean:
	rm $(NAME)

re: clean $(NAME)

