NAME =		wolf3d

CC =		@gcc

IFLAGS = 	-I/Users/anpichon/.brew/include/
CFLAGS =	$(IFLAGS) -lSDL2 -L/Users/anpichon/.brew/lib/

LIBGRAPH =	-framework OpenGL

RM =		rm -f

SRC =		srcs/main.c \
			srcs/init_param.c \
			srcs/texture_wall.c \
			srcs/key_and_event.c \
			srcs/position_and_ray.c

LFTDIR =	srcs/libft/libft.a

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

%.o: %.c
			$(CC) -Wall -Wextra -Werror $(IFLAGS) -o $@ -c $^

$(NAME): $(OBJ)
			@echo "\033[33mCompilate Library's...\033[0m\c"
			@make -C srcs/libft
			@echo "\033[32m                 [OK!]\033[0m"
			@echo "\033[33mCompilate Project's...\033[0m\c"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFTDIR) $(LIBGRAPH)
			@echo "\033[32m                 [OK!]\033[0m"

clean:
			@echo "\033[33mWolf3D Delete ...\033[0m\c"
			@$(RM) $(OBJ)
			@echo "\033[32m                      [OK!]\033[0m"
			@echo "\033[33mLibrary's Delete ...\033[0m\c"
			@make clean -C srcs/libft
			@echo "\033[32m                   [OK!]\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C srcs/libft

re:			fclean all

.PHONY: 	install clean fclean re
