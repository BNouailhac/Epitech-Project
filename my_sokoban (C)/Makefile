##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	= my_sokoban.c\
		my_putchar.c\
		my_put_nbr.c\
		map_to_str.c\
		my_strlen.c\
		my_putstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
