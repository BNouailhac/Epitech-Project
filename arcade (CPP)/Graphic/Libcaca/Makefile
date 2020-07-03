##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	=	liblibcaca.so

SRC_GRAPHIC =	libcaca.cpp\
		entryPoint.cpp

OBJ2	=	$(SRC_GRAPHIC:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra

CC	=	g++

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -c -Wall -Werror -fPIC $(SRC_GRAPHIC) `pkg-config --libs --cflags caca` -lcaca -lcaca++ -g3
		g++ -shared -o $(NAME) $(OBJ2) `pkg-config --libs --cflags caca` -lcaca -lcaca++ -g3
		mv liblibcaca.so ../../lib

clean	:
		$(RM) *~
		$(RM) include/*~
		$(RM) *~
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
