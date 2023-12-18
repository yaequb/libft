/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesques <nefdesq@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:03:40 by ndesques          #+#    #+#             */
/*   Updated: 2023/12/18 04:42:13 by ndesques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_strnum(char const *str, char c)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			res++;
		i++;
	}
	return (res);
}

static void	ft_strcpy(char *dest, char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

static void ft_free(char **tab, size_t *y)
{
	size_t	i;

	i = 0;
	while (i < *y)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}


static int	ft_walloc(char const *str, char **tab, char c)
{
	size_t	i;
	size_t	y;
	size_t	num;

	i = 0;
	y = 0;
	while (str[y])
	{
		num = 0;
		while (str[y + num] && str[y + num] != c)
			num++;
		if (num > 0)
		{
			tab[i] = malloc(sizeof(char) * (num + 1));
			if (!tab[i])
			{
				ft_free(tab, &i);
				return (0);
			}
			ft_strcpy(tab[i], (str + y), c);
			i++;
			y = y + num;
		}
		else
			y++;
	}
	tab[i] = 0;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	size_t	num;

	if (!str)
		return (NULL);
	num = ft_strnum(str, c);
	tab = malloc((num + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!ft_walloc(str, tab, c))
		return (NULL);
	return (tab);
}