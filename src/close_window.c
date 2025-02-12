/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:09:40 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/12 09:10:43 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, void *mlx)
{
	(void)mlx;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}
