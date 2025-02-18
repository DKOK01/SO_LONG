/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:41:53 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/18 14:50:13 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_common_textures(t_data *data)
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
}

void	free_collectible_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->img_collectibles[i])
			mlx_destroy_image(data->mlx, data->img_collectibles[i]);
		i++;
	}
}

void	free_textures(t_data *data)
{
	free_common_textures(data);
	free_collectible_textures(data);
}
