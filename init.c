/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:37:58 by bkhatib           #+#    #+#             */
/*   Updated: 2023/01/26 16:55:27 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->row = -1;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->filename = NULL;
	map->starting_pos = '\0';
	init_color(&map->floor_color);
	init_color(&map->ceilling_color);
	map->player.x = 0;
	map->player.y = 0;
}

void	init_game(t_program *game)
{
	init_map(&game->map);
	game->cub_content = NULL;
	game->screen_h = 480;
	game->screen_w = 640;
	game->x = 0;
}