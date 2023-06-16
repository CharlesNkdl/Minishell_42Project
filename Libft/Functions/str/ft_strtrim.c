/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:47:08 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:47:09 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	avt;
	size_t	arr;

	if (!s1 || !set)
		return (0);
	avt = 0;
	arr = ft_strlen(s1) - 1;
	while (s1[avt] && ft_strchr(set, s1[avt]))
		avt++;
	while (s1[arr] && ft_strchr(set, s1[arr]))
		arr--;
	return (ft_substr(s1, avt, ((arr + 1) - avt)));
}
/*int main(void)
{
    printf("%s\n",ft_strtrim("agougagaouga","ag"));
}*/
