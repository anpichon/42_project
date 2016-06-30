NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = Sources/main.c \
	  Sources/ft_get_tetrimino.c \
	  Sources/ft_check_tetri.c \
	  Sources/ft_map_and_ver.c \
	  Sources/ft_resolve_tetri.c \
	  Sources/ft_mv_tetri.c \
	  Sources/ft_libfunct.c

LFTDIR = Library/libft.a

NAMEPRG = fillit

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAMEPRG)
re: fclean all

.PHONY: clean fclean
