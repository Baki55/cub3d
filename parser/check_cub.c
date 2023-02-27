/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:04:19 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/27 11:05:19 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_cub_texture(char **content, int *i)
{
	int	found;

	found = 0;
	while (*i < 4 && content[*i])
	{
		if (ft_strncmp(content[*i], "NO ", 3) == 0
			|| ft_strncmp(content[*i], "SO ", 3) == 0
			|| ft_strncmp(content[*i], "WE ", 3) == 0
			|| ft_strncmp(content[*i], "EA ", 3) == 0)
			found++;
		(*i)++;
	}
	if (found != 4 && *i != found)
		ft_error("Texture error!\n");
	if (*i == 0)
		ft_error("Empty .cub file!\n");
}

void	check_cub_colors(char **content, int *i)
{
	int	found;
	int	j;
	int	ex;

	found = 0;
	ex = *i;
	j = *i + 2;
	while (*i < j && content[*i])
	{
		if (ft_strncmp(content[*i], "F ", 2) == 0
			|| ft_strncmp(content[*i], "C ", 2) == 0)
			found++;
		(*i)++;
	}
	if (*i - ex != found && found != 2)
		ft_error("Colors error\n");
}

void	check_cub(char **content)
{
	int	i;

	i = 0;
	check_cub_texture(content, &i);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	check_cub_colors(content, &i);
	while (content[i] && ft_strcmp(content[i], "\n") == 0)
		i++;
	if (!content[i])
		ft_error("Map doesn't exist!\n");
}
