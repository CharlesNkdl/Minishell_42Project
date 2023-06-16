/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:46:09 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:46:10 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lentotal;
	char	*join;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(lentotal + 1);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, lentotal + 1);
	return (join);
}
/*
int main(void)
{
    printf("%s\n", ft_strjoin ("cacaboudin","gros caca boudin"));
}*/
