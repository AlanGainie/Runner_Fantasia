##
## PERSONAL PROJECT, 2025-2027
## MAKEFILE
## File description:
## Appel de Makefile
##

SRC 	= 	src/setting.c \
			src/windows.c \
			src/initSprite.c \
			src/initIcon.c \
			src/initScene.c \
			src/initMacros.c \
			src/event/keyevent.c \
			src/pollEvent.c \
			src/log_message.c \
			src/draw.c \
			src/destroy.c \
			src/main.c \

BUILD_DIR	=	build

OBJ	=	$(SRC:%.c=$(BUILD_DIR)/%.o)

NAME 	= 	Runner_Fantasia

CFLAGS += -Wall -Wextra -Iinclude -L./lib/my/ -lmy -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ $(CFLAGS)

all : $(NAME)

$(NAME) : $(OBJ)
		$(MAKE) -C lib/my/
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(MAKE) -C lib/my/ clean
	rm -f $(OBJ)
fclean: clean
	rm -f lib/my/libmy.a
	rm -fr $(BUILD_DIR)
	rm -f $(NAME)

re:	 fclean all

auteur:
	echo $(USER) > auteur

debug:
	$(MAKE) -C lib/my/ debug
debug:	CFLAGS += -g
debug:	fclean $(NAME)

.PHONY : all $(NAME) clean fclean re debug
