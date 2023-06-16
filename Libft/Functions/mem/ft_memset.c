/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:44:37 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:44:38 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c_repl;
	unsigned char	*remplaptr;

	i = 0;
	c_repl = c;
	remplaptr = s;
	while (i++ < n)
	{
		*remplaptr++ = c_repl;
	}
	return (s);
}
