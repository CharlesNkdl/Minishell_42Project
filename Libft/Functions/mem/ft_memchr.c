/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:44:08 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:44:09 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;
	unsigned char	cp;
	size_t			i;

	i = 0;
	sptr = (unsigned char *) s;
	cp = c;
	while (i < n)
	{
		if (*(sptr + i) == cp)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
