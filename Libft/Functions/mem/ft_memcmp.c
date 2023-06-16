/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:44:15 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:44:16 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sptr;
	unsigned char	*scptr;

	if (s1 == s2 || n == 0)
		return (0);
	sptr = (unsigned char *)s1;
	scptr = (unsigned char *)s2;
	while (n--)
	{
		if ((*sptr) != (*scptr))
			return (*sptr - *scptr);
		if (n)
		{
			sptr++;
			scptr++;
		}
	}
	return (0);
}
