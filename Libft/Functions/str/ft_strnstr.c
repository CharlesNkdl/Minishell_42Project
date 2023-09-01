/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:46:54 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:46:55 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ct;
	size_t	ctw;
	size_t	check;

	ct = 0;
	ctw = 0;
	check = 0;
	if (little[ct] == '\0')
		return ((char *)big);
	if (!len)
		return (0);
	while (big[ct] && ct < len)
	{
		ctw = 0;
		check = 0;
		while (little[ctw] == big[ct + ctw] && (ct + ctw) < len)
		{
			check ++;
			ctw ++;
			if (check == ft_strlen(little))
				return ((char *)&big[ct]);
		}
		ct++;
	}
	return (NULL);
}
