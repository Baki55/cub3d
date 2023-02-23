/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:22:13 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/23 18:18:55 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		game_loop(t_program *p)
{
	t_img	texture_to_use;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_int(p->map.ceilling_color);
	floor_color = rgb_to_int(p->map.floor_color);
	p->x = 0;
	while (p->x < p->screen_w)
	{
		update_camera_raydir_delatdist(p);
		p->map_x = (int)p->pos_x;
		p->map_y = (int)p->pos_y;
		get_step_and_side_dist(p);
		search_wall(p);
		calculate_wall_size(p);
		texture_to_use = get_tex(p);
		init_tex(p, texture_to_use);
		put_tex(p, texture_to_use);
		draw_vertical_line(p, ceiling_color, floor_color);
		p->x++;
	}
	mlx_put_image_to_window(p->mlx, p->win_ptr, p->img.ptr, 0, 0);
	return (0);
}

void	load_textures(t_program *p)
{
	p->tex_north_img.ptr = mlx_xpm_file_to_image(p->mlx, p->map.north_texture,
		&p->tex_north_img.width, &p->tex_north_img.height);
	p->tex_north_img.arr = (int *)mlx_get_data_addr(p->tex_north_img.ptr,
		&p->tex_north_img.len, &p->tex_north_img.bpp, &p->tex_north_img.endian);
	p->tex_south_img.ptr = mlx_xpm_file_to_image(p->mlx, p->map.south_texture,
		&p->tex_south_img.width, &p->tex_south_img.height);
	p->tex_south_img.arr = (int *)mlx_get_data_addr(p->tex_south_img.ptr,
		&p->tex_south_img.len, &p->tex_south_img.bpp, &p->tex_south_img.endian);
	p->tex_west_img.ptr = mlx_xpm_file_to_image(p->mlx, p->map.west_texture,
		&p->tex_west_img.width, &p->tex_west_img.height);
	p->tex_west_img.arr = (int *)mlx_get_data_addr(p->tex_west_img.ptr,
		&p->tex_west_img.len, &p->tex_west_img.bpp, &p->tex_west_img.endian);
	p->tex_east_img.ptr = mlx_xpm_file_to_image(p->mlx, p->map.east_texture,
		&p->tex_east_img.width, &p->tex_east_img.height);
	p->tex_east_img.arr = (int *)mlx_get_data_addr(p->tex_east_img.ptr,
		&p->tex_east_img.len, &p->tex_east_img.bpp, &p->tex_east_img.endian);
}

static int	close_game(t_program *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	i = 0;
	while (game->cub_content[i])
		free(game->cub_content[i++]);
	free(game->cub_content);
	free(game->map.filename);
	free(game->map.north_texture);
	free(game->map.south_texture);
	free(game->map.west_texture);
	free(game->map.east_texture);
	mlx_destroy_image(game->mlx, game->img.ptr);
	mlx_destroy_image(game->mlx, game->tex_north_img.ptr);
	mlx_destroy_image(game->mlx, game->tex_south_img.ptr);
	mlx_destroy_image(game->mlx, game->tex_west_img.ptr);
	mlx_destroy_image(game->mlx, game->tex_east_img.ptr);
	mlx_destroy_window(game->mlx, game->win_ptr);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_program	p;
	
	if(argc != 2)
		ft_error("Usage: ./cub3D ./path_to_map\n");
	init_game(&p);
	p.map.filename = ft_strdup(argv[1]);
	if (p.map.filename == NULL)
		ft_error("Malloc failed\n");
	parser(&p);
	init_mlx_win_pos(&p);
	load_textures(&p);
	mlx_loop_hook(p.mlx, &game_loop, &p);
	mlx_hook(p.win_ptr, 2, 1L<<0, &move, &p);
	mlx_hook(p.win_ptr, 17, 0L, close_game, &p);
	mlx_loop(p.mlx);
}