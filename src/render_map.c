/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:56:40 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/14 20:59:34 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &w, &h);
	data->img_floor = mlx_xpm_file_to_image(data->mlx,
			"textures/Floor.xpm", &w, &h);
	data->img_player = mlx_xpm_file_to_image(data->mlx,
			"textures/Player.xpm", &w, &h);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"textures/Collectible.xpm", &w, &h);
	data->img_exit = mlx_xpm_file_to_image(data->mlx,
			"textures/Exit.xpm", &w, &h);
}

void	put_image_to_window(t_data *data, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_wall, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_floor, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_player, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_exit, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			put_image_to_window(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	free_textures(t_data *data)
{
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_player)
		mlx_destroy_image(data->mlx, data->img_player);
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
}
