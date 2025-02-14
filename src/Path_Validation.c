/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Path_Validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:37:49 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/13 19:03:22 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	is_valid_path(char **map, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(char **map, int x, int y, t_data *data)
{
	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'X')
		return ;
	map[x][y] = 'X';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

int	check_valid_path(t_data *data)
{
	char	**copy;
	int		valid;
	int		i;

	copy = (char **)malloc(data->rows * sizeof(char *));
	if (!copy)
		return (0);
	i = 0;
	while (i < data->rows)
	{
		copy[i] = ft_strdup(data->map[i]);
		if (!copy[i])
		{
			free_2d_array(copy, i);
			return (0);
		}
		i++;
	}
	find_player(data);
	flood_fill(copy, data->player_x, data->player_y, data);
	valid = is_valid_path(copy, data->rows, data->cols);
	free_2d_array(copy, data->rows);
	return (valid);
}
 