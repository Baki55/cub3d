/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:11:55 by blaurent          #+#    #+#             */
/*   Updated: 2023/02/12 17:11:55 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

static int	get_color(t_color color)
{
	return ((color.r << 16 | color.g << 8 | color.b));
}

void	draw_vertical_line(t_program *p, int color)
{
	int	y;

	y = 0;
	while (y < p->draw_start)
	{
		my_mlx_pixel_put(&(p)->img, p->x, y, get_color(p->map.ceilling_color));
		y++;
	}
	while (y < p->draw_end)
	{
		my_mlx_pixel_put(&(p)->img, p->x, y, color);
		y++;
	}
	while (y < p->screen_h)
	{
		my_mlx_pixel_put(&(p)->img, p->x, y, get_color(p->map.floor_color));
		y++;
	}
}
