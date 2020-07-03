##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##
SRC	=	my_strlen.asm\
		my_strchr.asm\
		my_memset.asm\
		my_strcmp.asm\
		my_strncmp.asm\
		my_rindex.asm\
		my_strstr.asm\
		my_strpbrk.asm\
		my_strcasecmp.asm\
		my_memcpy.asm

OBJ	=	$(SRC:.asm=.o)

%.o: %.asm
		nasm -o $@ $< -f elf64

NAME	=	libasm.so

all:	$(NAME)

$(NAME):	$(OBJ)
	ld -shared -fPIC -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
