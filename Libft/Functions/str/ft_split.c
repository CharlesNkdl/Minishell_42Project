/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:45:26 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/24 14:35:40 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	**ft_free(char **tabl, int i)
{
	int	j;

	j = 0;
	while (j < i && tabl[j])
	{
		free(tabl[j]);
		j++;
	}
	free(tabl);
	return (0);
}

static int	ft_lenword(char const *s, char c, unsigned int lenw)
{
	int	count;

	count = 0;
	while (s[lenw] == c && s[lenw])
		lenw++;
	while (s[lenw] && s[lenw] != c)
	{
		count ++;
		lenw++;
	}
	return (count);
}

static unsigned int	ft_countw(char const *s, char c)
{
	int	i;
	int	count;

	if (!s || !s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	**ft_fill(char const *s, char c, unsigned int i, char **tabl)
{
	unsigned int	lenw;
	unsigned int	j;

	lenw = 0;
	j = 0;
	while (++i < ft_countw(s, c))
	{
		j = 0;
		tabl[i] = (char *)malloc(ft_lenword(s, c, lenw) + 1);
		if (!tabl[i])
			return (ft_free(tabl, i));
		while (s[lenw] && s[lenw] == c)
			lenw++;
		while (s[lenw] && s[lenw] != c)
		{
			tabl[i][j] = s[lenw];
			j++;
			lenw++;
		}
		tabl[i][j] = 0;
	}
	tabl[i] = 0;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**tabl;

	if (!s)
		return (0);
	i = -1;
	tabl = (char **)malloc(((sizeof(char *)) * (ft_countw(s, c) + 1)));
	if (!tabl)
		return (NULL);
	ft_fill(s, c, i, tabl);
	return (tabl);
}
