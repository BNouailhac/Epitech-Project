##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

all: $(OBJ)
	make -C ./Snake
	make -C ./Pacman

clean:
	make clean -C ./Snake
	make clean -C ./Pacman

fclean: clean
	make fclean -C ./Snake
	make fclean -C ./Pacman

re: fclean all
