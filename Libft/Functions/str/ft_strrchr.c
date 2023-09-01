/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:47:02 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:47:03 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == find)
			return (((char *)s) + i);
		i--;
	}
	if (s[i] == find)
		return ((char *)s);
	return (0);
}
