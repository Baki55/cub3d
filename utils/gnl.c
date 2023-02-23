/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:39:28 by bkhatib           #+#    #+#             */
/*   Updated: 2023/02/23 18:15:46 by blaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*join_line(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

static char	*cpyline(char *file)
{
	char	*line;
	size_t	i;

	if (file[0] == '\0')
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		line[i] = file[i];
		i++;
	}
	line[i] = file[i];
	return (line);
}

static char	*point_nxtline(char *file)
{
	char	*nxtline;
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	i++;
	nxtline = malloc((ft_strlen(file + i) + 1) * sizeof(char));
	if (!nxtline)
		return (NULL);
	j = 0;
	while (file[i])
		nxtline[j++] = file[i++];
	nxtline[j] = '\0';
	free(file);
	return (nxtline);
}

static char	*readfile(char *file, int fd)
{
	char	*tmp;
	int		end;

	end = 1;
	tmp = ft_calloc(2, sizeof(char));
	while (!ft_strchr(tmp, '\n') && end != 0)
	{
		end = read(fd, tmp, 1);
		if (end == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[end] = '\0';
		file = join_line(file, tmp);
		if (!file)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0)
		return (NULL);
	file = readfile(file, fd);
	if (!file)
		return (NULL);
	line = cpyline(file);
	file = point_nxtline(file);
	return (line);
}
