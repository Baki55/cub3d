/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:22:13 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/08 15:36:01 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define KEY_UP 122
#define KEY_DOWN 115
#define KEY_RIGHT 100
#define KEY_LEFT 113

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
		p->x = 0;
		while (p->x < p->screen_w)
		{
			p->camera_x = 2 * p->x / (double)(p->screen_w) - 1;
			p->raydir_x = p->dir_x + p->plane_x * p->camera_x;
			p->raydir_y = p->dir_y + p->plane_y * p->camera_x;
			if (p->raydir_x == 0)
				p->delta_dist_x = 1e30;
			else
				p->delta_dist_x = fabs(1 / p->raydir_x);
			if (p->raydir_y == 0)
				p->delta_dist_y = 1e30;
			else
				p->delta_dist_y = fabs(1 / p->raydir_y);
			p->map_x = (int)p->pos_x;
			p->map_y = (int)p->pos_y;
			p->hit = 0;

			if (p->raydir_x < 0)
			{
				p->step_x = -1;
				p->side_dist_x = (p->pos_x - p->map_x) * p->delta_dist_x;
			}
			else
			{
				p->step_x = 1;
				p->side_dist_x = (p->map_x + 1.0 - p->pos_x) * p->delta_dist_x;
			}
			if (p->raydir_y < 0)
			{
				p->step_y = -1;
				p->side_dist_y = (p->pos_y - p->map_y) * p->delta_dist_y;
			}
			else
			{
				p->step_y = 1;
				p->side_dist_y = (p->map_y + 1.0 - p->pos_y) * p->delta_dist_y;
			}

			while (p->hit == 0)
			{
				if (p->side_dist_x < p->side_dist_y)
				{
					p->side_dist_x += p->delta_dist_x;
					p->map_x += p->step_x;
					p->side = 0;
				}
				else
				{
					p->side_dist_y += p->delta_dist_y;
					p->map_y += p->step_y;
					p->side = 1;
				}
				if (p->map.map[p->map_x][p->map_y] == '1')
					p->hit = 1;
			}

			if (p->side == 0)
				p->perp_wall_dist = (p->side_dist_x - p->delta_dist_x);
			else
				p->perp_wall_dist = (p->side_dist_y - p->delta_dist_y);
				
			p->line_height = (int)(p->screen_h / p->perp_wall_dist);

			p->draw_start = -(p->line_height) / 2 + p->screen_h / 2;
			if (p->draw_start < 0)
				p->draw_start = 0;
			p->draw_end = p->line_height / 2 + p->screen_h / 2;
			if (p->draw_end >= p->screen_h)
				p->draw_end = p->screen_h - 1;
			color = 0x00FF0000;
			if (p->side == 1)
				color = color / 2;
			draw_vertical_line(p, color);
			p->x++;
		}
		mlx_put_image_to_window(p->mlx, p->win_ptr, p->img.ptr, 0, 0);
		return (0);
}

int	move(int key, t_program *p)
{
	if (key == KEY_UP)
	{
		if (p->map.map[(int)(p->pos_x + (p->dir_x * 1))][(int)p->pos_y] == '0')
			p->pos_x += (p->dir_x * 1);
		if (p->map.map[(int)(p->pos_x)][(int)(p->pos_y + (p->dir_y * 1))] == '0')
			p->pos_y += p->dir_y * 1;
	}
	else if (key == KEY_DOWN)
	{
		if (p->map.map[(int)(p->pos_x - (p->dir_x * 1))][(int)p->pos_y] == '0')
			p->pos_x -= p->dir_x *1;
		if (p->map.map[(int)(p->pos_x)][(int)(p->pos_y - (p->dir_y * 1))] == '0')
			p->pos_y -= p->dir_y * 1;
	}
	// else if (key == KEY_RIGHT)
	// {
		
	// }
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
	p.mlx = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx, p.screen_w, p.screen_h, "CUB3D");
	p.img.ptr = mlx_new_image(p.mlx, p.screen_w, p.screen_h);
	p.img.addr = mlx_get_data_addr(p.img.ptr, &p.img.bpp, &p.img.len, &p.img.endian);
	p.pos_x = p.map.player.x + 0.5;
	p.pos_y = p.map.player.y + 0.5;
	p.map.map[p.map.player.x][p.map.player.y] = '0';
	p.dir_x = -1;
	p.dir_y = 0; //initial direction vector
	p.plane_x = 0;
	p.plane_y = 0.66;
	mlx_loop_hook(p.mlx, &game_loop, &p);
	mlx_key_hook(p.win_ptr, &move, &p);
	mlx_loop(p.mlx);
}