/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:34:05 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/13 18:15:02 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size(char *filename, int *rows, int *cols)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	*rows = 0;
	line = get_next_line(fd);
	if (line)
		*cols = ft_strlen(line) - (line[ft_strlen(line) - 1] == '\n');
	while (line)
	{
		(*rows)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

char	**read_map(char *filename, int rows)
{
	int		fd;
	char	**map;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (close(fd), NULL);
	i = 0;
	while (i < rows)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (close(fd), free_2d_array(map, i), NULL);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

char	**load_map(char *filename, t_data *data)
{
	char	**map;

	if (!get_map_size(filename, &(data->rows), &(data->cols)))
		return (NULL);
	map = read_map(filename, data->rows);
	return (map);
}
