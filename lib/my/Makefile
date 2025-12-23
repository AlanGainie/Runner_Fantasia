##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

SRC 	=	my_strcat.c \


CFLAGS += -I ../../include/

%.o:	%.c
	@gcc -c -o $@ $^ $(CFLAGS)

OBJ = 	$(SRC:.c=.o)

NAME = 	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	 fclean all

debug: CFLAGS += -g
debug: fclean all

auteur:
	echo $(USER) > auteur

.PHONY : all clean fclean re debug
