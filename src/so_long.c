/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:32:24 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/15 14:44:02 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_file_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len <= 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	validate_map(t_data *data)
{
	if (!is_rectangular(data))
		return (print_error("Error: The map is not rectangular!\n"), 0);
	if (!is_surrounded_by_walls(data))
		return (print_error("Error: The map is not surrounded by walls!\n"), 0);
	if (!check_map_elements(data))
	{
		print_error("Error: The map must have 1 player(P), 1 exit(E) ");
		print_error("and at least 1 collectible (C)!\n");
		return (0);
	}
	if (!check_invalid_chars(data))
		return (print_error("Error: Invalid characters in map!\n"), 0);
	if (!check_valid_path(data))
		return (print_error("Error: The map does not have a valid path!\n"), 0);
	print_error("The map is valid! ✅\n");
	return (1);
}

void	initialize_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->cols * TILE_SIZE,
			data->rows * TILE_SIZE, "THE LITTLE SPIRIT");
	load_textures(data);
	render_map(data);
}

int	validate_and_load_map(t_data *data, char *map_file)
{
	if (!is_valid_file_extension(map_file))
		return (print_error("Error: Invalid file: (filename.ber)\n"), 0);
	data->map = load_map(map_file, data);
	if (!data->map)
		return (print_error("Error: Failed to load map!\n"), 0);
	if (!validate_map(data))
	{
		print_error("Error: Invalid map!\n");
		free_2d_array(data->map, data->rows);
		return (0);
	}
	return (1);
}

void	run_game_loop(t_data *data)
{
	data->player_on_exit = 0;
	mlx_hook(data->mlx_win, 2, 1L << 0, handle_key, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (print_error("Error: ./so_long [map.ber]\n"), 1);
	if (!validate_and_load_map(&data, av[1]))
		return (1);
	initialize_game(&data);
	run_game_loop(&data);
	free_textures(&data);
	free_2d_array(data.map, data.rows);
	return (0);
}
