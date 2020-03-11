##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME =	libmy_malloc.so

SRC =	malloc.c \
		free.c \
		calloc.c \
		realloc.c \
		reallocarray.c \

OBJ =	$(SRC:.c=.o)

CC =	gcc

CFLAGS =	-Wall -Wextra -fPIC

LIBFLAG =

RM =	rm -f



RULE =	all

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) $(LIBFLAG) -g -shared -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re: fclean all
