##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME	=	arcade

SRC	=	Core/main.cpp\
		SRC_Games/GameLibLoader.cpp\
		Graphic/GraphLibLoader.cpp\
		Core/Arcade.cpp

SRC_GRAPHIC =	Graphic/GraphicExample.cpp

OBJ	=	$(SRC:.cpp=.o)

OBJ2	=	$(SRC_GRAPHIC:.cpp=.o)

CFLAGS	=	-W -Wall -Wextra

CC	=	g++

RM	=	rm -f

OBJSNM	=	$(SRCSNM:.c=.o)

NAMENM	=	my_nm

all:	$(NAME)

core	: 
		$(CC) -o $(NAME) $(OBJ) -ldl

graphicals	:
		make -C ./Graphic

games	:
		make -C ./SRC_Games

game	:
		make -C ./SRC_Games

Games	:
		make -C ./SRC_Games

$(NAME):	$(OBJ)
		make -C ./Graphic
		make -C ./SRC_Games
		$(CC) -o $(NAME) $(OBJ) -ldl

clean	:
		$(RM) *~
		make clean -C ./Graphic
		make clean -C ./SRC_Games
		$(RM) include/*~
		$(RM) src/*~
		$(RM) src/*.o

fclean	:	clean
		make fclean -C ./Graphic
		make fclean -C ./SRC_Games
		$(RM) $(NAME)

re	:	fclean all
