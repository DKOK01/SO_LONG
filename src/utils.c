/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:09:40 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/22 12:09:21 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	free_textures(data);
	free_2d_array(data->map, data->rows);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void	print_error(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
}

void	free_2d_array(char **array, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	is_valid_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (print_error("Error: Invalid filename: (filename.ber)\n"), 0);
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
		return (print_error("Error: Invalid file extension!\n"), 0);
	if (filename[len - 5] == '/')
		return (print_error("Error: Invalid filename: (filename.ber)\n"), 0);
	return (1);
}
