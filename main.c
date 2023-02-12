/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:22:13 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/12 15:57:42 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_vertical_line(t_program *p, int color)
{
	int	y;

	y = 0;
	while (y < p->draw_start)
	{
		my_mlx_pixel_put(&(p)->img, p->x, y, 0xFFFFFFF0);
		y++;
	}
	while (y < p->draw_end)
	{
		my_mlx_pixel_put(&(p)->img, p->x, y, color);
		y++;
	}
	while (y < p->screen_h)
	{
		my_mlx_pixel_put(&(p)->img, p->x, y, 0);
		y++;
	}
}

int		game_loop(t_program *p)
{
	int color;

	p->x = 0;
	while (p->x < p->screen_w)
	{
		update_camera_raydir_delatdist(p);
		p->map_x = (int)p->pos_x;
		p->map_y = (int)p->pos_y;
		get_step_and_side_dist(p);
		search_wall(p);
		calculate_wall_size(p);
		color = 0x00FF0000;
		if (p->side == 1)
			color = color / 2;
		draw_vertical_line(p, color);
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