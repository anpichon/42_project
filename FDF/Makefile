NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRC = Sources/main.c \
	  Sources/fdf_algo.c \
	  Sources/fdf_display.c \
	  Sources/fdf_event.c \
	  Sources/fdf_pars.c \
	  Sources/fdf_view.c \
	  Sources/fdf_check.c

LFTDIR = sources/libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C sources/libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LFTDIR)
	@echo "****** FDF COMPILATE ! ******"

clean:
	@$(RM) $(OBJ)
	@echo "****** FDF DELETED ! ******"
	@make clean -C sources/libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C sources/libft

re: fclean all

.PHONY: clean fclean
