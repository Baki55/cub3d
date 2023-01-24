/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:31:24 by bkhatib           #+#    #+#             */
/*   Updated: 2023/01/24 21:03:58 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_player_surroundings(char **map, int row, int col)
{
	if (map[row][col + 1] == ' ' || map[row][col - 1] == ' '
		|| map[row + 1][col] == ' ' || map[row - 1][col] == ' ')
		ft_error("Invalid map\n");
	return (EXIT_SUCCESS);
}

void	check_map(char **map)
{
	int	row;
	int	col;
	int	found;

	row = 0;
	found = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (!in_charset(map[row][col], " 01NSEW"))
				ft_error("Invalid character found in map.\n");
			if (in_charset(map[row][col], "NSEW")
				&& !check_player_surroundings(map, row, col))
				found++;
			col++;
		}
		row++;
	}
	if (!found)
		ft_error("Player not found.\n");
	else if (found > 1)
		ft_error("This is not a multiplayer game ..\n");
}

void	map_checks2(t_map map, int row, int col)
{
	if ((row == 0 && check_wall(map.map, row, col))
		|| (row == map.row - 1 && check_wall(map.map, row, col)))
		ft_error("Invalid map!.\n");
	else if (col == 0 && check_wall(map.map, row, col))
		ft_error("Invalid map!.\n");
	else if (col == ft_strlen(map.map[row]) - 1
		&& check_wall(map.map, row, col))
		ft_error("Invalid map!.\n");
	else if ((row > 0 && row < map.row - 1)
		&& (col > 0 && col < ft_strlen(map.map[row]) - 1))
	{
		if (map.map[row][col] == '0'
			&& (map.map[row + 1][col] == ' ' || map.map[row - 1][col] == ' '
			|| map.map[row][col + 1] == ' ' || map.map[row][col - 1] == ' '))
			ft_error("Invalid map!.\n");
	}
}

void	check_full_map(t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (map.map[row])
	{
		col = 0;
		if (check_extended_wall(map.map, row))
			ft_error("Invalid map!. (new)\n");
		while (map.map[row][col])
		{
			map_checks2(map, row, col);
			col++;
		}
		row++;
	}
}