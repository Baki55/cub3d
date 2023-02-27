/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:12:14 by blaurent          #+#    #+#             */
/*   Updated: 2023/02/12 15:12:14 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_camera_raydir_delatdist(t_program *p)
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
}

void	get_step_and_side_dist(t_program *p)
{
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
}

void	search_wall(t_program *p)
{
	int	hit;

	hit = 0;
	while (hit == 0)
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
			hit = 1;
	}
}

void	calculate_wall_size(t_program *p)
{
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
}
