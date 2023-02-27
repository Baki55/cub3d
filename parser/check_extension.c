/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:53:43 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/27 11:05:38 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_extension(char *src, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(src) - ft_strlen(to_find);
	while ((src[j] && to_find[i]) && (src[j] == to_find[i]))
	{
		i++;
		j++;
	}
	if (j == ft_strlen(src))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
