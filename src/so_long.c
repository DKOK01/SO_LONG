/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:32:24 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/12 13:09:26 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_error(char *msg)
{
	while (*msg)
		write(2, msg++, 1);
}

void	print_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int validate_map(char **map, int rows, int cols, t_data *data)
{
	if (!is_rectangular(map, rows, cols))
	{
		print_error("Error: The map is not rectangular!\n");
		return (0);
	}
	if (!is_surrounded_by_walls(map, rows, cols))
	{
		print_error("Error: The map is not surrounded by walls!\n");
		return (0);
	}
	if (!check_map_elements(data))
	{
		print_error("Error: The map must have 1 player (P), 1 exit (E), and at least 1 collectible (C)!\n");
		return (0);
	}
	if (!check_invalid_chars(data))
	{
		print_error("Error: Invalid characters in map!\n");
		return (0);
	}
	if (!check_valid_path(data))
	{
		print_error("Error: The map does not have a valid path!\n");
		return (0);
	}
	print_error("The map is valid! ✅\n");
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);

	data.map = load_map(av[1], &data.rows, &data.cols);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "DARK SOULS");
	printf("Rows: %d, Cols: %d\n", data.rows, data.cols);
	if (!data.map)
	{
		print_error("Error: Failed to load map!\n");
		return (1);
	}
	if (!validate_map(data.map, data.rows, data.cols, &data))
	{
		print_error("Error: Invalid map!\n");
		free_2d_array(data.map, data.rows);
		return (1);
	}
	print_map(data.map, data.rows);

	mlx_key_hook(data.mlx_win, handle_key, 0);
	mlx_hook(data.mlx_win, 17, 0, &close_window, &data);

	mlx_loop(data.mlx);
	free_2d_array(data.map, data.rows);
	return (0);
}
