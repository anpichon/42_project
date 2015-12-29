NAME= libfillit.a

CC= gcc

CFLAGS= -Wall -Wextra -Werror

RM=rm -f

SRC= Sources/main.c

LFTDIR= Library/libft.a

NAMEPRG= fillit

OBJ=$(SRC:.c=.o)

$(NAME):
	$(CC) -o $(NAMEPRG) $(SRC) $(LFTDIR)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
