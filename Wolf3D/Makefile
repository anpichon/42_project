NAME =		wolf3d

CC =		@gcc

CFLAGS =	-Wall -Wextra -Werror

LIBGRAPH =	-framework OpenGL -framework SDL2

RM =		rm -f

SRC =		srcs/main.c \
			srcs/init_param.c \
			srcs/texture_wall.c \
			srcs/key_and_event.c \
			srcs/position_and_ray.c

LFTDIR =	srcs/libft/libft.a

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
			@echo "\033[33mCompilate Library's...\033[0m\c"
			@make -C srcs/libft
			@echo "\033[32m                 [OK!]\033[0m"
			@echo "\033[33mCompilate Project's...\033[0m\c"
			@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LFTDIR) $(LIBGRAPH)
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

.PHONY: 	clean fclean
