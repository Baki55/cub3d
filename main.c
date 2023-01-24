/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:22:13 by bkhatib           #+#    #+#             */
/*   Updated: 2023/01/24 21:38:10 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_program	game_ptr;
	
	if(argc != 2)
		ft_error("Usage: ./cub3D ./path_to_map\n");
	init_game(&game_ptr);
	game_ptr.map.filename = ft_strdup(argv[1]);
	parser(&game_ptr);
}