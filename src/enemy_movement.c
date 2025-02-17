#include "so_long.h"

void move_enemy(t_data *data, int enemy_x, int enemy_y)
{
	if (enemy_x < data->cols - 1 && data->map[enemy_y][enemy_x + 1] == '0')
	{
		data->map[enemy_y][enemy_x] = '0';
		data->map[enemy_y][enemy_x + 1] = 'X';
	}
	else if (enemy_x > 0 && data->map[enemy_y][enemy_x - 1] == '0')
	{
		data->map[enemy_y][enemy_x] = '0';
		data->map[enemy_y][enemy_x - 1] = 'X';
	}
}

int move_all_enemies(t_data *data)
{
	int y = 0;
	while (y < data->rows)
	{
		int x = 0;
		while (x < data->cols)
		{
			if (data->map[y][x] == 'X')
			{
				move_enemy(data, x, y);
				render_map(data);
			}
			x++;
		}
		y++;
	}
	return (1);
}

