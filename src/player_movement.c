/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 13:20:45 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/17 13:47:37 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_previous_tile(t_data *data)
{
	if (data->player_on_exit)
		data->map[data->player_y][data->player_x] = 'E';
	else
		data->map[data->player_y][data->player_x] = '0';
}

void	check_new_tile(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'E')
		data->player_on_exit = 1;
	else
		data->player_on_exit = 0;
	if (data->map[new_y][new_x] == 'C')
	{
		data->collectible--;
		data->map[new_y][new_x] = '0';
	}
	if (data->map[new_y][new_x] == 'E' && data->collectible == 0)
	{
		print_error("Congratulations! You won!\n");
		close_window(data);
	}
	if (data->map[new_y][new_x] == 'X')
	{
		print_error("Game Over! You lost!\n");
		close_window(data);
	}
}

void	move_player(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= data->cols || new_y >= data->rows)
		return ;
	if (data->map[new_y][new_x] == '1')
		return ;
	update_previous_tile(data);
	check_new_tile(data, new_x, new_y);
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[new_y][new_x] = 'P';
	data->move_count++;
	render_map(data);
	display_moves(data);
}

int	handle_key(int keycode, t_data *data)
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
