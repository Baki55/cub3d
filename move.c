/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:00:22 by blaurent          #+#    #+#             */
/*   Updated: 2023/02/12 15:00:22 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define KEY_UP 122
#define KEY_DOWN 115
#define KEY_RIGHT 100
#define KEY_LEFT 113

static void	move_straight(t_program *p)
{
	if (p->map.map[(int)(p->pos_x + (p->dir_x * 0.2))][(int)p->pos_y] == '0')
		p->pos_x += (p->dir_x * 0.2);
	if (p->map.map[(int)(p->pos_x)][(int)(p->pos_y + (p->dir_y * 0.2))] == '0')
		p->pos_y += (p->dir_y * 0.2);
}

static void	move_forward(t_program *p)
{
	if (p->map.map[(int)(p->pos_x - (p->dir_x * 0.2))][(int)p->pos_y] == '0')
		p->pos_x -= (p->dir_x * 0.2);
	if (p->map.map[(int)(p->pos_x)][(int)(p->pos_y - (p->dir_y * 0.2))] == '0')
		p->pos_y -= (p->dir_y * 0.2);
}

static void	rotate_right(t_program *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(-0.1) - p->dir_y * sin(-0.1);
	p->dir_y = old_dir_x * sin(-0.1) + p->dir_y * cos(-0.1);
	p->plane_x = p->plane_x * cos(-0.1) - p->plane_y * sin(-0.1);
	p->plane_y = old_plane_x * sin(-0.1) + p->plane_y * cos(-0.1);
}

static void	rotate_left(t_program *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	old_plane_x = p->plane_x;
	p->dir_x = p->dir_x * cos(0.1) - p->dir_y * sin(0.1);
	p->dir_y = old_dir_x * sin(0.1) + p->dir_y * cos(0.1);
	p->plane_x = p->plane_x * cos(0.1) - p->plane_y * sin(0.1);
	p->plane_y = old_plane_x * sin(0.1) + p->plane_y * cos(0.1);
}

int	move(int key, t_program *p)
{
	if (key == KEY_UP)
		move_straight(p);
	if (key == KEY_DOWN)
		move_forward(p);
	if (key == KEY_RIGHT)
		rotate_right(p);
	if (key == KEY_LEFT)
		rotate_left(p);
	return (0);
}