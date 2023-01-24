/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:12:40 by bkhatib           #+#    #+#             */
/*   Updated: 2023/01/24 20:12:48 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

static int	num_len(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	char	tmp;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
	return (str);
}

static void	check_negative(int *n, unsigned int *nbr, size_t *nl)
{
	if (*n <= 0)
	{
		*nbr = -(*n);
		(*nl)++;
	}
}

char	*ft_itoa(int n)
{
	char			*num;
	size_t			i;
	size_t			nl;
	unsigned int	nbr;

	i = 0;
	nl = 0;
	nbr = n;
	check_negative(&n, &nbr, &nl);
	nl += num_len(n);
	num = malloc(sizeof(char) * (nl + 1));
	if (!num)
		return (NULL);
	if (n == 0)
		num[i++] = '0';
	while (nbr)
	{
		num[i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		num[i++] = '-';
	num[i] = 0;
	return (ft_strrev(num));
}
