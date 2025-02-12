/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_Validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:29:35 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/12 11:50:44 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map, int rows, int cols)
{
	int	i;
	int	len;

	i = 0;
	while (i < rows)
	{
		len = ft_strlen(map[i]);
		if (len != cols)
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map, int rows, int cols)
{
	int	i;

	if (rows == 0 || cols == 0 || !map)
		return (0); 
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	count_elements(t_data *data)
{
	int	i;
	int	j;

	data->player = 0;
	data->exit = 0;
	data->collectible = 0;
	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] == 'P')
				data->player++;
			else if (data->map[i][j] == 'E')
				data->exit++;
			else if (data->map[i][j] == 'C')
				data->collectible++;
			j++;
		}
		i++;
	}
}

int	check_map_elements(t_data *data)
{
	count_elements(data);
	if (data->player != 1 || data->exit != 1 || data->collectible < 1)
		return (0);
	return (1);
}
int	check_invalid_chars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] != '0' && data->map[i][j] != '1' &&
				data->map[i][j] != 'P' && data->map[i][j] != 'E' &&
				data->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
