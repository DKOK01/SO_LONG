#include "so_long.h"

void	move_enemy(t_data *data, int enemy_x, int enemy_y)
{
	if (data->map[enemy_y][enemy_x + 1] == '0')
	{
		data->map[enemy_y][enemy_x] = '0';
		data->map[enemy_y][enemy_x + 1] = 'X';
	}
	else if (data->map[enemy_y][enemy_x - 1] == '0')
	{
		data->map[enemy_y][enemy_x] = '0';
		data->map[enemy_y][enemy_x - 1] = 'X';
	}
}

int	move_all_enemies(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->rows)
	{
		x = 0;
		while (x < data->cols)
		{
			if (data->map[y][x] == 'X')
			{
				move_enemy(data, x, y);
			}
			x++;
		}
		y++;
	}
	return (1);
}

