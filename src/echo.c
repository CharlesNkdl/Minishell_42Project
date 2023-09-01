/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:03:24 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/23 20:29:53 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	ft_pimp_strncmp(char *s)
{
	int	i;

	i = 1;
	if (s[0] != '-' || s[1] != 'n')
		return (0);
	while (s[i] != '\0' && s[i] != ' ')
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	initntr(t_ntr *n, char *str)
{
	n->len = 0;
	n->i = 1;
	n->n = 0;
	n->s = ft_split(str, ' ');
}

void	ft_echo(t_data *m, t_token *tok)
{
	t_ntr	n;
	t_token	*tmp;

	tmp = tok;
	initntr(&n, tok->content);
	if (n.s[1])
	{
		n.opt = ft_pimp_strncmp(n.s[1]);
		if (n.opt == 1)
		{
			n.n = 1;
			while (n.opt == 1)
			{
				n.len = n.len + ft_strlen(n.s[n.i]) + 1;
				n.i++;
				n.opt = ft_pimp_strncmp(n.s[n.i]);
			}
		}
		ft_putstr_fd(&tmp->content[5 + n.len], m->out);
	}
	if (n.n == 0)
		ft_putchar_fd('\n', m->out);
	free_arr(n.s);
	ft_freem(m, 0);
	exit(EXIT_SUCCESS);
}
