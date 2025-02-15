/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysadeq <aysadeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:25:07 by aysadeq           #+#    #+#             */
/*   Updated: 2025/02/15 15:30:04 by aysadeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_itoa(int n)
{
	char	*str;
	int		len;
	int		nbr;

	nbr = n;
	len = 1;
	while (nbr /= 10)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

void	display_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->move_count);
	mlx_string_put(data->mlx, data->mlx_win, 10, 10, 0xFFFFFF, "Moves: ");
	mlx_string_put(data->mlx, data->mlx_win, 60, 10, 0xFFFFFF, moves);
	free(moves);
}
