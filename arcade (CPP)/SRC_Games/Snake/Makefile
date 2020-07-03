##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	=	lib_arcade_nibbler.so

SRC_GRAPHIC =	Snake.cpp\
				entryPoint.cpp

OBJ2	=	$(SRC_GRAPHIC:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra

CC	=	g++

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -c -fPIC $(SRC_GRAPHIC)
		g++ -shared -o $(NAME) $(OBJ2)
		mv lib_arcade_nibbler.so ../../games/

clean	:
		$(RM) *~
		$(RM) include/*~
		$(RM) *~
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
