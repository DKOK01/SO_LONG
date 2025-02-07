CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c
OBJ = $(SRC:.c=.o)
NAME = so_long
MLXFLAGS = -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
