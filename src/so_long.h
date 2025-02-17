/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:21:22 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/17 13:22:35 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define TILE_SIZE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

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

	int		enemy_x;
	int		enemy_y;

	int		player;
	int		exit;
	int		collectible;

	void	*img_enemy;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;

	int		player_on_exit;
	int		move_count;

}	t_data;

int		close_window(t_data *data);
void	free_2d_array(char **array, int rows);
void	print_error(char *msg);
// get_next_line functions
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
// map functions
char	**load_map(char *filename, t_data *data);
// validation functions
int		is_rectangular(t_data *data);
int		is_surrounded_by_walls(t_data *data);
int		check_map_elements(t_data *data);
int		check_invalid_chars(t_data *data);
int		is_valid_file_extension(char *filename);
// path finding functions
int		check_valid_path(t_data *data);
// rendering functions
void	load_textures(t_data *data);
void	render_map(t_data *data);
void	free_textures(t_data *data);
// player movement functions
int		handle_key(int keycode, t_data *data);
void	display_moves(t_data *data);

int	move_enemy(t_data *data);

#endif
