/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:56:40 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/18 14:47:18 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_animation(t_data *data)
{
	display_moves(data);
	data->animation_counter++;
	if (data->animation_counter % 9000 == 0)
	{
		data->collectible_frame = (data->collectible_frame + 1) % 6;
		render_map(data);
	}
	return (0);
}

void	put_player_image(t_data *data, int x, int y)
{
	int	px;
	int	py;

	py = y * TILE_SIZE;
	px = x * TILE_SIZE;
	if (data->player_facing_right)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_player_right, px, py);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_player_left, px, py);
}

void	put_exit_image(t_data *data, int x, int y)
{
	int	px;
	int	py;

	py = y * TILE_SIZE;
	px = x * TILE_SIZE;
	if (data->collectible == 0)
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_exit_open, px, py);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_exit_closed, px, py);
}

void	put_image_to_window(t_data *data, char tile, int x, int y)
{
	int	px;
	int	py;

	py = y * TILE_SIZE;
	px = x * TILE_SIZE;
	if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_wall, px, py);
	else if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_floor, px, py);
	else if (tile == 'P')
		put_player_image(data, x, y);
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_collectibles[data->collectible_frame], px, py);
	else if (tile == 'E')
		put_exit_image(data, x, y);
	else if (tile == 'X')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->img_enemy, px, py);
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
