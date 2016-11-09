NAME =		Wolf3D

CC =		@gcc

CFLAGS =	-Wall -Wextra -Werror -I srcs/minilibx -L srcs/minilibx -lmlx -framework OpenGL -framework AppKit

RM =		rm -f

SRC =

LFTDIR =	srcs/libft/libft.a

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME): $(OBJ)
			@echo "\033[33mCompilate Library's...\033[0m\c"
			@make -C srcs/libft
			@echo "\033[32m                 [OK!]\033[0m"
			@echo "\033[33mCompilate MLX...\033[0m\c"
			@make -C srcs/minilibx
			@echo "\033[32m                       [OK!]\033[0m"
			@echo "\033[33mCompilate Project's...\033[0m\c"
			@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LFTDIR)
			@echo "\033[32m                 [OK!]\033[0m"

clean:
			@echo "\033[33mWolf3D Delete ...\033[0m\c"
			@$(RM) $(OBJ)
			@echo "\033[32m                      [OK!]\033[0m"
			@echo "\033[33mLibrary's Delete ...\033[0m\c"
			@make clean -C srcs/libft
			@echo "\033[32m                   [OK!]\033[0m"
			@echo "\033[33mMLX Delete ...\033[0m\c"
			@make clean -C srcs/minilibx
			@echo "\033[32m                         [OK!]\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C srcs/libft

re:			fclean all

.PHONY: 	clean fclean
