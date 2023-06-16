/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:49:39 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/24 14:49:41 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

unsigned int	ft_strlenptf(char *str);
void			ft_putcharptf(char c);
int				ft_analyze(char c, va_list ptr);
int				ft_print_memory(unsigned long long nbr);
int				ft_putnbru(unsigned int nbr);
int				ft_putnbr_base(int nbr, char *base);
int				ft_putstrptf(char *str);
int				ft_putchar_count(char c);
int				ft_printf(const char *str, ...);
int				ft_putnbr_b(size_t nbr, char *base);
int				ft_putnbr_baseptr(unsigned long long nbr, char *base);

#endif
