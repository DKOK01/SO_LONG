CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/close_window.c src/Map.c src/Map_Validation.c src/get_next_line.c src/get_next_line_utils.c src/Path_Validation.c
OBJ = $(SRC:.c=.o)
NAME = so_long
MLXFLAGS = -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
