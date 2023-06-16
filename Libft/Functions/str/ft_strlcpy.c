/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:46:25 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:46:26 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	count;
	size_t	len;

	len = ft_strlen(src);
	count = 1;
	if (size >= 1)
	{
		while ((count < size) && (*src != '\0'))
		{
			*dst = *src;
			src += 1;
			dst += 1;
			count++;
		}
		*dst = '\0';
	}
	return (len);
}
