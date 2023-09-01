/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begininit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:17 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:26:18 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	ft_init_tokens(t_data *m, int in, int out)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (m->line[i] && m->line[i] == ' ')
		i++;
	if (m->line[i])
		tmp = ft_strtrim(m->line, " ");
	else
		return ;
	free(m->line);
	m->line = tmp;
	m->token = NULL;
	m->heredoc = 0;
	m->pid = -1;
	m->fd[0] = -1;
	m->fd[1] = -1;
	m->std[0] = in;
	m->std[1] = out;
	ft_check_parameters(m, 0);
}

void	ft_inifir(t_data *m, int in, int out)
{
	m->exit_status = 0;
	m->token = NULL;
	m->heredoc = 0;
	m->pid = -1;
	m->fd[0] = -1;
	m->fd[1] = -1;
	m->std[0] = in;
	m->std[1] = out;
}
