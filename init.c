/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:37:58 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/12 16:36:44 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_starting_position(t_program *p)
{
	p->pos_x = p->map.player.x + 0.5;
	p->pos_y = p->map.player.y + 0.5;
	if (p->map.starting_pos == 'N')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = 0.66;
	}
	else if (p->map.starting_pos == 'S')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->plane_x = 0;
		p->plane_y = -0.66;
	}
	else if (p->map.starting_pos == 'W')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->plane_x = -0.66;
		p->plane_y = 0;
	}
	else if (p->map.starting_pos == 'E')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->plane_x = 0.66;
		p->plane_y = 0;
	}
	p->map.map[p->map.player.x][p->map.player.y] = '0';
}

void	init_mlx_win_pos(t_program *p)
{
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		ft_error("mlx_init failed\n");
	p->win_ptr = mlx_new_window(p->mlx, p->screen_w, p->screen_h, "CUB3D");
	p->img.ptr = mlx_new_image(p->mlx, p->screen_w, p->screen_h);
	p->img.addr = mlx_get_data_addr(p->img.ptr, &p->img.bpp, &p->img.len, &p->img.endian);
	init_starting_position(p);
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
	game->screen_h = 480;
	game->screen_w = 640;
	game->x = 0;
}