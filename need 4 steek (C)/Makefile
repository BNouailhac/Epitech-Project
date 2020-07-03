##
## EPITECH PROJECT, 2018
## Makefile
## File description:
##
##

SRC	=	src/car.c\
		src/main.c\
		src/itoa.c\
		src/my_str_to_word_array.c\
		src/get_next_line.c \
		src/things2.c			\
		src/things.c

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
