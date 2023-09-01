/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:46:38 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:46:39 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*sptr;

	if (!s)
		return (NULL);
	sptr = ft_strdup(s);
	if (!sptr)
		return (NULL);
	i = 0;
	if (sptr != NULL || f != NULL)
	{
		while (s[i])
		{
			sptr[i] = f(i, s[i]);
			i++;
		}
	}
	sptr[i] = 0;
	return (sptr);
}
