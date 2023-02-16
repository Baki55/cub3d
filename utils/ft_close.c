/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:15:15 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/16 17:19:29 by bkhatib          ###   ########.fr       */
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
	free(game->map.filename);
	mlx_destroy_window(game->mlx, game->win_ptr);
	exit(EXIT_SUCCESS);
}