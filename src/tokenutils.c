/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:02 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:26:03 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	ft_splitok(t_data *m)
{
	t_token	*tmp;

	tmp = m->token;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->i = 0;
	}
}

void	ft_addt(t_data *m, char c, char *s, int i)
{
	char	*buffer;
	t_token	*tmp;

	if (!m->token)
		ft_addtsub(m, c, s, i);
	else
	{
		tmp = m->token;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->i == 0)
			ft_addtsub(m, c, s, i);
		else
		{
			buffer = ft_strjoin(tmp->content, s);
			if (tmp->content)
				free(tmp->content);
			if (s)
				free(s);
			tmp->content = buffer;
		}
	}
}

void	ft_addtsub(t_data *m, char c, char *s, int i)
{
	t_token	*new;
	t_token	*tmp;

	if (!s && c == WORD)
		return ;
	new = malloc(sizeof(t_token));
	new->i = i;
	new->c = c;
	new->content = s;
	new->next = NULL;
	if (!m->token)
		m->token = new;
	else
	{
		tmp = m->token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int	ft_symbol(char c)
{
	if (c == '\'')
		return (1);
	if (c == '"')
		return (2);
	if (c == '\0')
		return (3);
	if (c == ' ' || c == '\t' || c == '\v')
		return (4);
	if (c == REDIRR)
		return (5);
	if (c == REDIRL)
		return (6);
	if (c == PIP)
		return (7);
	return (0);
}

int	nextok(t_data *m, char token)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = m->token;
	tmp2 = NULL;
	if (tmp)
		tmp2 = tmp->next;
	while (tmp2 && tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
	if (!tmp2 || (tmp2 && tmp2->i == 1))
		tmp2 = tmp;
	if (tmp2 && tmp2->c == token)
		return (1);
	return (0);
}
