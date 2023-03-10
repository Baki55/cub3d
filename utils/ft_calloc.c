/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:49:04 by blaurent          #+#    #+#             */
/*   Updated: 2022/01/12 15:49:04 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (count > (count * size) || size > (count * size))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		ft_error("Malloc failed\n");
	ft_bzero(p, count * size);
	return (p);
}
