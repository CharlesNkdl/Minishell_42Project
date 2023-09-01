/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:40:03 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:40:05 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char const *nptr)
{
	int	count;
	int	countsignneg;
	int	result;

	count = 0;
	countsignneg = 1;
	result = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || (nptr[count] == 32))
		count++;
	if (nptr[count] == 45 || nptr[count] == 43)
	{
		if (nptr[count] == 45)
			countsignneg *= -1;
		count ++;
	}
	while (nptr[count] >= 48 && nptr[count] <= 57)
	{
		result = result * 10 + (nptr[count] - 48);
		count ++;
	}
	return (result * countsignneg);
}
