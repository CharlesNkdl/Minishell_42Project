/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:44:59 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:45:00 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	temp;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		temp = nb * -1;
	}
	else
		temp = nb;
	if (temp >= 10)
		ft_putnbr_fd(temp / 10, fd);
	ft_putchar_fd((char)(temp % 10 + 48), fd);
}
