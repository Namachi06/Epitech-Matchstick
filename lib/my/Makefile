##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## COUCOU
##

SRC		=	get_next_line.c \
			my_char_isalpha.c \
			my_put_nbr.c \
			my_putchar.c \
			my_putstr.c \
			my_str_to_int.c \
			my_str_isalpha.c

DEST_LIB_DIR	=	.

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):
	gcc -g -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
