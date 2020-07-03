##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

all: $(OBJ)
	make -C ./ncurse
	make -C ./SDL
	make -C ./Libcaca

clean:
	make clean -C ./ncurse
	make clean -C ./SDL
	make clean -C ./Libcaca

fclean: clean
	make fclean -C ./ncurse
	make fclean -C ./SDL
	make fclean -C ./Libcaca

re: fclean all
