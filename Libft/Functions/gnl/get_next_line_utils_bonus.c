/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:06:45 by cnikdel           #+#    #+#             */
/*   Updated: 2023/05/03 18:26:43 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoingnl(char *s1, char *s2)
{
	size_t	lenone;
	size_t	lentwo;
	char	*join;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2[0])
		return (s1);
	lenone = ft_strlengnl(s1, 1);
	lentwo = ft_strlengnl(s2, 1);
	join = (char *)malloc(lenone + lentwo + 1);
	if (!join)
		return (NULL);
	ft_strlcpygnl(join, s1, lenone + 1);
	ft_strlcpygnl(&join[lenone], s2, (lentwo + 1));
	free(s1);
	return (join);
}

char	*ft_strrchrgnl(char const *s, int c, int *count)
{
	char	find;
	size_t	i;

	find = (unsigned char)c;
	i = ft_strlengnl(s, 1);
	if (!s)
		return (NULL);
	while (i > 0)
	{
		if (s[i] == find)
			return (((char *)s) + i);
		i--;
	}
	if (s[i] == find)
	{
		return ((char *)s);
	}
	*count += i;
	return (0);
}

size_t	ft_strlcpygnl(char *dst, char const *src, size_t size)
{
	size_t	count;
	size_t	len;

	len = ft_strlengnl(src, 1);
	count = 0;
	if (!size)
		return (len);
	while (src[count] && count < (size - 1))
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (len);
}

size_t	ft_strlengnl(char const *s, int version)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (version == 1)
	{
		while (s[i])
			i++;
		return (i);
	}
	else if (version == 2)
	{
		while (s[i] != '\n' && s[i])
			i++;
		return (i);
	}
	return (i);
}
