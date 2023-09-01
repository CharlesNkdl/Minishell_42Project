/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokentwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:55 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:26:56 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	ft_pipe(t_data *m, int i)
{
	ft_splitok(m);
	ft_addt(m, PIP, NULL, 0);
	return (i);
}

int	ft_word(t_data *m, int i)
{
	if (m->line[i] == ' ' || m->line[i] == '\v' || m->line[i] == '\t')
	{
		ft_splitok(m);
		while (m->line[i] == ' ' || m->line[i] == '\v' || m->line[i] == '\t')
			i++;
		return (i);
	}
	ft_addt(m, WORD, ft_substr(m->line, i, 1), 1);
	return (i + 1);
}
