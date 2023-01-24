/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:11:16 by bkhatib           #+#    #+#             */
/*   Updated: 2023/01/24 20:11:51 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *error)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}