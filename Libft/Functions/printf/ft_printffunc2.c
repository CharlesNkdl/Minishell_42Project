/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printffunc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:49:18 by cnikdel           #+#    #+#             */
/*   Updated: 2023/05/03 18:28:27 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_memory(unsigned long long nbr)
{
	int	count;

	if (nbr == 0)
		return (ft_putstrptf("(nil)"));
	count = ft_putstrptf("0x");
	return (count + ft_putnbr_baseptr(nbr, "0123456789abcdef"));
}

int	ft_putnbru(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_putnbru(nbr / 10);
	count += ft_putchar_count((nbr % 10) + 48);
	return (count);
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	temp;
	unsigned int	len;
	int				count;

	count = 0;
	len = ft_strlenptf(base);
	if (nbr < 0)
	{
		ft_putcharptf('-');
		count++;
		temp = nbr * -1;
	}
	else
		temp = nbr;
	if (temp >= (unsigned int)ft_strlenptf(base))
		count += ft_putnbr_base((temp / len), base);
	count += ft_putchar_count(base[temp % len]);
	return (count);
}

unsigned int	ft_strlenptf(char *str)
{
	unsigned int	count;

	count = 0;
	while (*str != '\0')
	{
		str += 1;
		count++;
	}
	return (count);
}
