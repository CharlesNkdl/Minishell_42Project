/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:46:18 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:46:19 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	while (dst[i] != '\0')
		++i;
	r = 0;
	while (src[r] != '\0')
		++r;
	if (size <= i)
		r = r + size;
	else
		r = r + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (r);
}
