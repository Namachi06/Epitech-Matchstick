##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## COUCOU
##

LIB_PATH	=	./lib/my

SRC		=	src/main.c \
			src/matchstick.c \
			src/utils.c \
			src/display.c \
			src/player.c \
			src/ia.c

OBJ		=	$(SRC:.c=.o)

NAME	=	matchstick

all: make_lib $(NAME)

$(NAME): $(OBJ)
	gcc -g $(SRC) -o $(NAME) -I./include -L./lib/my -lmy

clean:
	rm -f $(OBJ)

fclean: clean_lib clean
	rm -f $(NAME)

re: fclean all

make_lib:
	cd $(LIB_PATH) && $(MAKE) re

clean_lib:
	cd $(LIB_PATH) && $(MAKE) fclean
