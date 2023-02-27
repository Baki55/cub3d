/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:36:36 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/27 11:05:49 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall(char **map, int row, int col)
{
	if (map[row][col] != '1' && map[row][col] != ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_wall2(char **map, int row, int i)
{
	while (map[row][i])
	{
		if (map[row][i] != '1' && map[row][i] != ' ')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_extended_wall(char **map, int row)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(map[row]);
	l2 = 0;
	if (map[row + 1])
		l2 = ft_strlen(map[row + 1]);
	if (l1 > l2 && l2 > 0)
	{
		if (check_wall2(map, row, l2))
			return (EXIT_FAILURE);
	}
	else if (l2 > l1)
	{
		if (check_wall2(map, row + 1, l1))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
