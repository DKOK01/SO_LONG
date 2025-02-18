/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:43:43 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/18 14:55:53 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_static_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->img_wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm", &w, &h);
	data->img_floor = mlx_xpm_file_to_image(data->mlx,
			"textures/Floor.xpm", &w, &h);
	data->img_player_left = mlx_xpm_file_to_image(data->mlx,
			"textures/Player_left.xpm", &w, &h);
	data->img_exit_closed = mlx_xpm_file_to_image(data->mlx,
			"textures/Exit_close.xpm", &w, &h);
	data->img_enemy = mlx_xpm_file_to_image(data->mlx,
			"textures/Enemy.xpm", &w, &h);
	data->img_player_right = mlx_xpm_file_to_image(data->mlx,
			"textures/Player_right.xpm", &w, &h);
	data->img_exit_open = mlx_xpm_file_to_image(data->mlx,
			"textures/Exit_open.xpm", &w, &h);
}

void	load_collectible_textures(t_data *data)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	data->img_collectibles[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/coin1.xpm", &w, &h);
	data->img_collectibles[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/coin2.xpm", &w, &h);
	data->img_collectibles[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/coin3.xpm", &w, &h);
	data->img_collectibles[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/coin4.xpm", &w, &h);
	data->img_collectibles[4] = mlx_xpm_file_to_image(data->mlx,
			"textures/coin5.xpm", &w, &h);
	data->img_collectibles[5] = mlx_xpm_file_to_image(data->mlx,
			"textures/coin6.xpm", &w, &h);
}

void	load_textures(t_data *data)
{
	load_static_textures(data);
	load_collectible_textures(data);
	data->collectible_frame = 0;
	data->animation_counter = 0;
}
