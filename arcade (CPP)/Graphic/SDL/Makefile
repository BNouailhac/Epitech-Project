##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	=	libsdl.so

SRC_GRAPHIC =	sdl.cpp\
		entryPoint.cpp

OBJ2	=	$(SRC_GRAPHIC:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra

CC	=	g++

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -c -Wall -fPIC $(SRC_GRAPHIC) `sdl-config --cflags --libs` -lSDL_ttf -lSDL_image -lncurses
		g++ -shared -o $(NAME) $(OBJ2) `sdl-config --cflags --libs` -lSDL_ttf -lSDL_image -lncurses
		mv libsdl.so ../../lib/

clean	:
		$(RM) *~
		$(RM) include/*~
		$(RM) *~
		$(RM) *.o

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
