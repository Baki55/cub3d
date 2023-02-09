/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:47:27 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/09 18:14:52 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parser(t_program *ptr)
{
	if(check_extension(ptr->map.filename, ".cub") == EXIT_FAILURE)
		ft_error("Wrong extension.\n");
	get_cub(ptr);
	check_cub(ptr->cub_content);
	get_map_textures(ptr);
	get_colors(ptr);
	get_map(ptr);
	get_player_pos(&ptr->map);
	check_map(ptr->map.map);
	check_full_map(ptr->map);
}