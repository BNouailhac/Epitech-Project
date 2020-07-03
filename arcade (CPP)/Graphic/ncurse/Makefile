##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	=	libncurse.so

SRC_GRAPHIC =	ncurse.cpp\
		entryPoint.cpp

OBJ2	=	$(SRC_GRAPHIC:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra

CC	=	g++

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -c -Wall -Werror -fPIC $(SRC_GRAPHIC) -lncurses
		g++ -shared -o $(NAME) $(OBJ2) -lncurses
		mv libncurse.so ../../lib/

clean	:
		$(RM) *~
		$(RM) include/*~
		$(RM) *~
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
