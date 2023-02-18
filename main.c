/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:22:13 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/18 21:14:27 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		game_loop(t_program *p)
{
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
		get_tex(p);
		init_tex(p);
		put_tex(p);
		draw_vertical_line(p, ceiling_color, floor_color);
		p->x++;
	}
	mlx_put_image_to_window(p->mlx, p->win_ptr, p->img.ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	p;
	
	if(argc != 2)
		ft_error("Usage: ./cub3D ./path_to_map\n");
	init_game(&p);
	p.map.filename = ft_strdup(argv[1]);
	parser(&p);
	init_mlx_win_pos(&p);
	mlx_loop_hook(p.mlx, &game_loop, &p);
	mlx_hook(p.win_ptr, 2, 1L<<0, &move, &p);
	mlx_loop(p.mlx);
}