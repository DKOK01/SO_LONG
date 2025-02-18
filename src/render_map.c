/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:56:40 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/18 09:35:13 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_collectibles(t_data *data)
{
	data->collectible_frame++;
	if (data->collectible_frame > 5)
		data->collectible_frame = 0;
	return (1);
}

void	load_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &w, &h);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "textures/Floor.xpm", &w, &h);
	data->img_player_left = mlx_xpm_file_to_image(data->mlx, "textures/Player_left.xpm", &w, &h);
	data->img_exit_closed = mlx_xpm_file_to_image(data->mlx, "textures/Exit_close.xpm", &w, &h);
	data->img_enemy = mlx_xpm_file_to_image(data->mlx, "textures/Enemy.xpm", &w, &h);
	data->img_player_right = mlx_xpm_file_to_image(data->mlx, "textures/Player_right.xpm", &w, &h);
	data->img_exit_open = mlx_xpm_file_to_image(data->mlx, "textures/Exit_open.xpm", &w, &h);
	data->img_collectibles[0] = mlx_xpm_file_to_image(data->mlx, "textures/coin1.xpm", &w, &h);
	data->img_collectibles[1] = mlx_xpm_file_to_image(data->mlx, "textures/coin2.xpm", &w, &h);
	data->img_collectibles[2] = mlx_xpm_file_to_image(data->mlx, "textures/coin3.xpm", &w, &h);
	data->img_collectibles[3] = mlx_xpm_file_to_image(data->mlx, "textures/coin4.xpm", &w, &h);
	data->img_collectibles[4] = mlx_xpm_file_to_image(data->mlx, "textures/coin5.xpm", &w, &h);
	data->img_collectibles[5] = mlx_xpm_file_to_image(data->mlx, "textures/coin6.xpm", &w, &h);
	data->collectible_frame = 0;
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
	{
		if (data->player_facing_right)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player_right, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player_left, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_collectibles[data->collectible_frame], x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
	{
		if (data->collectible == 0)
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_exit_open, x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_exit_closed, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'X')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_enemy, x * TILE_SIZE, y * TILE_SIZE);

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
	if (data->img_player_left)
		mlx_destroy_image(data->mlx, data->img_player_left);
	if (data->img_exit_closed)
		mlx_destroy_image(data->mlx, data->img_exit_closed);
	if (data->img_enemy)
		mlx_destroy_image(data->mlx, data->img_enemy);
	if (data->img_player_right)
		mlx_destroy_image(data->mlx, data->img_player_right);
	if (data->img_exit_open)
		mlx_destroy_image(data->mlx, data->img_exit_open);
	if (data->img_collectibles[0])
		mlx_destroy_image(data->mlx, data->img_collectibles[0]);
	if (data->img_collectibles[1])
		mlx_destroy_image(data->mlx, data->img_collectibles[1]);
	if (data->img_collectibles[2])
		mlx_destroy_image(data->mlx, data->img_collectibles[2]);
	if (data->img_collectibles[3])
		mlx_destroy_image(data->mlx, data->img_collectibles[3]);
	if (data->img_collectibles[4])
		mlx_destroy_image(data->mlx, data->img_collectibles[4]);
	if (data->img_collectibles[5])
		mlx_destroy_image(data->mlx, data->img_collectibles[5]);
}
