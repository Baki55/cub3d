/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:36 by bkhatib           #+#    #+#             */
/*   Updated: 2023/01/24 20:20:39 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_separator(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *sep)
{
	int	i;
	int	w_count;
	int	state;

	i = 0;
	w_count = 0;
	state = 0;
	while (str[i])
	{
		if (!is_separator(str[i], sep))
		{
			if (!state)
				w_count++;
			state = 1;
			i++;
		}
		else
		{
			state = 0;
			i++;
		}
	}
	return (w_count);
}

char	*ft_strdup_w(char *str, int *index, char *sep)
{
	char	*word;
	int		len;
	int		i;

	i = *index;
	len = 0;
	while (str[i] && !is_separator(str[i++], sep))
		len++;
	word = (char *) malloc(len + 1);
	if (!word)
		ft_error("Malloc failed\n");
	i = 0;
	while (str[*index])
	{
		if (!is_separator(str[*index], sep))
		{
			word[i++] = str[*index];
			(*index)++;
		}
		else
			break ;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *sep)
{
	char	**arr_str;
	int		i;
	int		words;
	int		w_i;

	i = 0;
	w_i = 0;
	words = count_words(str, sep);
	arr_str = (char **) malloc((words + 1) * 8);
	if (!arr_str)
		ft_error("Malloc failed\n");
	while (w_i < words)
	{
		while (is_separator(str[i], sep) && str[i])
			if (!str[i++])
				break ;
		arr_str[w_i] = ft_strdup_w(str, &i, sep);
		w_i++;
	}
	arr_str[words] = 0;
	return (arr_str);
}
