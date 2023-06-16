/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:44:22 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:44:23 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destptr;
	unsigned char	*srcptr;

	if (!dest && !src)
		return (0);
	i = 0;
	destptr = dest;
	srcptr = (unsigned char *)src;
	while (i++ < n)
	{
		*destptr++ = *srcptr++;
	}
	return (dest);
}
