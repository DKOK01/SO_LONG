/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:21:22 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/14 21:22:52 by aysadeq          ###   ########.fr       */
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

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;

}	t_data;

int		handle_key(int keycode, void *mlx);
int		close_window(t_data *data);
void	print_map(char **map);
void	free_2d_array(char **array, int rows);
void	print_error(char *msg);

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);

char	**load_map(char *filename, t_data *data);

int		is_rectangular(t_data *data);
int		is_surrounded_by_walls(t_data *data);
int		check_map_elements(t_data *data);
int		check_invalid_chars(t_data *data);

int		check_valid_path(t_data *data);

void	load_textures(t_data *data);
void	render_map(t_data *data);
void	free_textures(t_data *data);

#endif
