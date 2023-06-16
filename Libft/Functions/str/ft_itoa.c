/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:42:04 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:42:15 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_ct(int nb, int *count);
static void	ft_checkintmin(int *n, char *s, int *j);

char	*ft_itoa(int n)
{
	int		i;
	char	*ptr;
	int		j;

	i = 0;
	j = 0;
	ft_putnbr_ct(n, &i);
	ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	ft_checkintmin(&n, ptr, &j);
	while (i > j)
	{
		*(ptr + (i - 1)) = (unsigned char)(n % 10 + 48);
		n /= 10;
		i--;
	}
	return (ptr);
}

static void	ft_checkintmin(int *n, char *s, int *j)
{
	if (*n < 0)
	{
		s[0] = '-';
		if (*n == -2147483648)
		{
			s[1] = '2';
			*n = 147483648;
			*j = *j + 1;
		}
		else
			*n *= -1;
		*j = *j + 1;
	}
}

static void	ft_putnbr_ct(int nb, int *count)
{
	unsigned int	temp;

	if (nb < 0)
	{
		*count += 1;
		temp = nb * -1;
	}
	else
		temp = nb;
	if (temp >= 10)
	{
		*count += 1;
		ft_putnbr_ct(temp / 10, count);
	}
	else
		*count += 1;
}
