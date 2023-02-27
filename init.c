/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:37:58 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/27 11:33:25 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_starting_position(t_program *p)
{
	p->pos_x = p->map.player.x + 0.5;
	p->pos_y = p->map.player.y + 0.5;
	p->dir_x = 0.00000000;
	p->dir_y = 0.00000000;
	p->plane_x = 0.00000000;
	p->plane_y = 0.00000000;
	if (p->map.starting_pos == 'N')
		p->dir_x = -1;
	else if (p->map.starting_pos == 'S')
		p->dir_x = 1;
	else if (p->map.starting_pos == 'W')
		p->dir_y = -1;
	else if (p->map.starting_pos == 'E')
		p->dir_y = 1;
	if (p->dir_x != 0.0 && ft_strchr("NS", p->map.starting_pos))
		p->plane_y = 0.66 * -(p->dir_x);
	else if (p->dir_x != 0.0 && ft_strchr("WE", p->map.starting_pos))
		p->plane_y = 0.66 * p->dir_x;
	else if (p->dir_y != 0.0 && ft_strchr("NS", p->map.starting_pos))
		p->plane_x = 0.66 * -(p->dir_y);
	else if (p->dir_y != 0.0 && ft_strchr("WE", p->map.starting_pos))
		p->plane_x = 0.66 * p->dir_y;
}

void	init_mlx_win_pos(t_program *p)
{
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		ft_error("mlx_init failed\n");
	p->win_ptr = mlx_new_window(p->mlx, p->screen_w, p->screen_h, "CUB3D");
	p->img.ptr = mlx_new_image(p->mlx, p->screen_w, p->screen_h);
	p->img.addr = mlx_get_data_addr(p->img.ptr, &p->img.bpp,
			&p->img.len, &p->img.endian);
	init_starting_position(p);
	p->map.map[p->map.player.x][p->map.player.y] = '0';
}

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
	game->screen_h = SCREEN_H;
	game->screen_w = SCREEN_W;
	game->x = 0;
}
