/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:57:29 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/09 18:10:00 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_cub(t_program *ptr)
{
	int	len;
	int	fd;
	int	i;

	i = 0;
	len = nbr_lines(ptr->map.filename);
	ptr->cub_content = malloc(sizeof(char *) * (len + 1));
	if (!ptr->cub_content)
		ft_error("Malloc Error: parser.c: 81\n");
	fd = open(ptr->map.filename, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	ptr->cub_content[i] = get_next_line(fd);
	while (i < len && ptr->cub_content[i++])
		ptr->cub_content[i] = get_next_line(fd);
	ptr->cub_content[i] = 0;
	close(fd);
}