#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#define	WIDTH 900
#define HEIGHT 500

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	**map;
	int		rows;
	int		cols;
	int		player_x;
	int		player_y;
	int		player;
	int		exit;
	int		collectible;

}	t_data;

int		handle_key(int keycode, void *mlx);
int		close_window(t_data *data);

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

char	**load_map(char *filename, int *rows, int *cols);
void	print_map(char **map, int rows);
int		is_rectangular(char **map, int rows, int cols);
int		is_surrounded_by_walls(char **map, int rows, int cols);
int		check_map_elements(t_data *data);
int		check_valid_path(t_data *data);
void	free_2d_array(char **array, int rows);
int		check_invalid_chars(t_data *data);

#endif
