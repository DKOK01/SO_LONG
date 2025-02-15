/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:20:45 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/15 13:20:46 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= data->cols || new_y >= data->rows)
		return ;
	if (data->map[new_y][new_x] == '1')
		return ;
	if (data->map[new_y][new_x] == 'C')
	{
		data->collectible--;
		data->map[new_y][new_x] = '0';
	}
	if (data->map[new_y][new_x] == 'E' && data->collectible == 0)
	{
		print_error("Congratulations! You won!\n");
		close_window(data);
		return;
	}
	data->map[data->player_y][data->player_x] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[new_y][new_x] = 'P';
	render_map(data);
}

int handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == ARROW_UP)
		move_player(data, data->player_x, data->player_y - 1);
	else if (keycode == KEY_S || keycode == ARROW_DOWN)
		move_player(data, data->player_x, data->player_y + 1);
	else if (keycode == KEY_A || keycode == ARROW_LEFT)
		move_player(data, data->player_x - 1, data->player_y);
	else if (keycode == KEY_D || keycode == ARROW_RIGHT)
		move_player(data, data->player_x + 1, data->player_y);
	else if (keycode == KEY_ESC)
		close_window(data);
	return (0);
}
