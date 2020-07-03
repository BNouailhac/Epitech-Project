##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##
SRC	=	src/main.c\
		src/my_ftp.c\
		src/send_handling.c\
		src/send_handling2.c\
		src/send_handling3.c\
		src/tool.c\
		src/tool2.c\
		src/tool3.c

OBJ	=	$(SRC:.c=.o)

NAME	=	myftp

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
