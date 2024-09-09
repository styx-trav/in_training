CC=gcc
CCFLAGS=-Wall -Wextra -Werror
HEADERS=./includes/ft.h
NEWOBJS= ./srcs/ft_putchar.o ./srcs/ft_swap.o ./srcs/ft_putstr.o ./srcs/ft_strlen.o ./srcs/ft_strcmp.o
SRCS= ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
CMPND=ft_putchar.c ft_putstr.c ft_swap.c ft_strlen.c ft_strcmp.c

.PHONY: all clean fclean hello

all: libft.a

libft.a: $(SRCS)
	(cd srcs; $(CC) $(CCFLAGS) -c $(CMPND) .$(HEADERS))
	ar cr $@ $(SRCS) $(NEWOBJS) $(HEADERS)

fclean: clean
	rm ./includes/ft.h.gch
#rid of binary ? figured it out

re: fclean all

clean:
	rm $(NEWOBJS)
	rm libft.a

hello:
	echo "Hello, World"
