CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/so_long.c src/utils.c src/Map.c src/Map_Validation.c src/get_next_line.c src/get_next_line_utils.c src/Path_Validation.c \
	src/render_map.c src/player_movement.c src/display_moves.c src/load_textures.c src/free_textures.c
OBJ = $(SRC:.c=.o)
NAME = so_long
MLXFLAGS = -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

bonus: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
