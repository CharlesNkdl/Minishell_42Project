/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execredir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:36 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:26:37 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

t_token	*deltok(t_data *m, t_token *tmp, t_token *tmp2)
{
	if (m->token && tmp && m->token == tmp)
	{
		m->token = m->token->next;
		tmp2 = m->token;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
	else if (m->token && tmp)
	{
		tmp2 = m->token;
		while (tmp2 && tmp2->next != tmp)
			tmp2 = tmp2->next;
		if (tmp2)
		{
			tmp2->next = tmp->next;
			if (tmp->content)
				free(tmp->content);
			free(tmp);
			tmp2 = tmp2->next;
		}
	}
	return (tmp2);
}

int	exredirtwo(t_token *tmp, t_data *m, int i)
{
	if (i != -1 && (tmp->c == REDIRR || tmp->c == REREDIRR))
	{
		if (m->out > 1)
			close(m->out);
		m->out = accessperm(tmp->content, tmp->c);
	}
	else if (i != -1 && tmp->c == REDIRL)
	{
		if (m->in > 0)
			close(m->in);
		m->in = accessperm(tmp->content, tmp->c);
	}
	else if (tmp->c == REREDIRL)
	{
		if (m->in > 0)
			close(m->in);
		m->in = heredocread(i, m);
	}
	return (i);
}

t_token	*exredir(t_data *m, t_token *tmp, int i, int j)
{
	t_token	*tmp2;

	tmp2 = NULL;
	while (tmp && tmp->c != PIP)
	{
		i = exredirtwo(tmp, m, i);
		if (tmp->c == WORD && !j)
		{
			j++;
			tmp2 = tmp;
		}
		if (!i && (m->in < 0 || m->out < 0))
		{
			i = -1;
			m->exit_status = 1;
		}
		if (tmp->c == REDIRR || tmp->c == REREDIRL || tmp->c == REDIRL
			|| tmp->c == REREDIRR)
			tmp = deltok(m, tmp, 0);
		else
			tmp = tmp->next;
	}
	return (tmp2);
}
