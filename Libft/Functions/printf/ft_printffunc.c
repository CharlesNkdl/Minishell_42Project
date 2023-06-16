/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printffunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:49:24 by cnikdel           #+#    #+#             */
/*   Updated: 2023/05/03 18:27:56 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrptf(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstrptf("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar_count(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putcharptf(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr_b(size_t nbr, char *base)
{
	unsigned int	len;
	int				count;

	len = ft_strlenptf(base);
	count = 0;
	if (nbr >= len)
		count += ft_putnbr_b((nbr / len), base);
	count += ft_putchar_count(base[nbr % len]);
	return (count);
}

int	ft_putnbr_baseptr(unsigned long long nbr, char *base)
{
	unsigned int	len;
	int				count;

	len = ft_strlenptf(base);
	count = 0;
	if (nbr >= len)
		count += ft_putnbr_baseptr((nbr / len), base);
	count += ft_putchar_count(base[nbr % len]);
	return (count);
}
