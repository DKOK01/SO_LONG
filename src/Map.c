/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:34:05 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/12 13:39:23 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_cols(char *filename)
{
	char	*line;
	int		fd;
	int		cols;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	cols = ft_strlen(line);
	if (line[ft_strlen(line) - 1] == '\n')
		cols--;
	free(line);
	close(fd);
	return (cols);
}

int	count_rows(char *filename)
{
	char	*line;
	int		fd;
	int		rows;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	rows = i;
	close(fd);
	free(line);
	return (rows);
}

char	**load_map(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	data->cols = count_cols(filename);
	data->rows = count_rows(filename);
	if (data->rows == 0 || data->cols == 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc((data->rows) * (sizeof(char *)));
	if (!map)
		return (close(fd), NULL);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	return (close(fd), free(line), map);
}
