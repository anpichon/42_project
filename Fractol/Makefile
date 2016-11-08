NAME =		fractol

CFLAGS +=	-Wall -Wextra -Werror -I src/minilibx -L src/minilibx -lmlx -framework OpenGL -framework AppKit

RM =		rm -f

SRC =		src/main.c \
			src/fractol_display.c \
			src/fractol_init.c \
			src/fractol_init_pt2.c \
			src/fractol_color.c \
			src/fractol_key.c \
			src/fractol_key_pt2.c \
			src/fractol_cal.c \
			src/fractol_cal_pt2.c



LFTDIR =	src/libft/libft.a

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
			@echo "\033[33mCompilate Library's...\033[0m\c"
			@make -C src/libft
			@echo "\033[32m                 [OK!]\033[0m"
			@echo "\033[33mCompilate MLX...\033[0m\c"
			@make -C src/minilibx
			@echo "\033[32m                       [OK!]\033[0m"
			@echo "\033[33mCompilate Project's...\033[0m\c"
			@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LFTDIR)
			@echo "\033[32m                 [OK!]\033[0m"

clean:
			@echo "\033[33mFractol Delete ...\033[0m\c"
			@$(RM) $(OBJ)
			@echo "\033[32m                     [OK!]\033[0m"
			@echo "\033[33mLibrary's Delete ...\033[0m\c"
			@make clean -C src/libft
			@echo "\033[32m                   [OK!]\033[0m"
			@echo "\033[33mMLX Delete ...\033[0m\c"
			@make clean -C src/minilibx
			@echo "\033[32m                         [OK!]\033[0m"

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C src/libft

re:			fclean all

.PHONY: 	clean fclean
