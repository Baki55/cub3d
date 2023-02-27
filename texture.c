/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:31:13 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/27 18:14:26 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

t_img	get_tex(t_program *game_ptr)
{
	if (game_ptr->side == 0 && game_ptr->step_x == -1)
		return (game_ptr->tex_north_img);
	if (game_ptr->side == 0 && game_ptr->step_x == 1)
		return (game_ptr->tex_south_img);
	if (game_ptr->side == 1 && game_ptr->step_y == -1)
		return (game_ptr->tex_west_img);
	if (game_ptr->side == 1 && game_ptr->step_y == 1)
		return (game_ptr->tex_east_img);
	return (game_ptr->tex_north_img);
}

void	init_tex(t_program *game_ptr, t_img tex)
{
	if (game_ptr->side == 0)
		game_ptr->wallx = game_ptr->pos_y + game_ptr->perp_wall_dist * \
		game_ptr->raydir_y;
	else
		game_ptr->wallx = game_ptr->pos_x + game_ptr->perp_wall_dist * \
		game_ptr->raydir_x;
	game_ptr->wallx -= (int)((game_ptr->wallx));
	game_ptr->tex_x = (int)(game_ptr->wallx * (double)(tex.width));
	if (game_ptr->side == 0 && game_ptr->raydir_x > 0)
		game_ptr->tex_x = tex.width - game_ptr->tex_x - 1;
	if (game_ptr->side == 1 && game_ptr->raydir_y < 0)
		game_ptr->tex_x = tex.width - game_ptr->tex_x - 1;
	game_ptr->tex_step = 1.0 * tex.height / game_ptr->line_height;
	game_ptr->tex_pos = (game_ptr->draw_start - game_ptr->screen_h \
		/ 2 + game_ptr->line_height / 2) * game_ptr->tex_step;
}

void	put_tex(t_program *game_ptr, t_img tex)
{
	int	color;
	int	y;

	y = game_ptr->draw_start;
	while (y < game_ptr->draw_end)
	{
		game_ptr->tex_y = (int)game_ptr->tex_pos & (tex.height - 1);
		game_ptr->tex_pos += game_ptr->tex_step;
		color = tex.arr[tex.height * game_ptr->tex_y + game_ptr->tex_x];
		my_mlx_pixel_put(&(game_ptr->img), game_ptr->x, y, color);
		y++;
	}
}
