/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:15:15 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/23 18:11:07 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	ft_close(t_program *game)
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