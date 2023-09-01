/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:30:30 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/23 18:42:40 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	ft_export(t_data *m, t_token *tok)
{
	if (ft_strcmp(tok->content, "export") == 0)
		ft_export_solo(m);
	else
		ft_do_export(m, tok);
	ft_envdd(m, 0);
	return ;
}

void	ft_export_solo(t_data *m)
{
	t_env	*current;
	int		c;

	c = 0;
	while (c <= 127)
	{
		current = m->env;
		while (current != NULL)
		{
			if (current->key[0] == c)
			{
				ft_putstr_fd("declare -x ", m->out);
				ft_putstr_fd(current->key, m->out);
				ft_putchar_fd('=', m->out);
				ft_putendl_fd(current->content, m->out);
			}
			current = current->next;
		}
		c++;
	}
}

void	ft_do_export(t_data *m, t_token *tok)
{
	char	**s;
	t_token	*tmp;
	int		i;

	i = 1;
	tmp = tok;
	s = ft_split(tmp->content, ' ');
	while (s[i])
	{
		if (ft_verif_key(s[1], m) == 0 && s[i][0] != '=')
			ft_change_content(s, m);
		else if (ft_verif_export(s[i]) != 0 && s[i][0] != '=')
			m = ft_gugugaga(s[i], m);
		i++;
	}
	free_arr(s);
}

int	ft_verif_key(char *s, t_data *m)
{
	t_env	*tmp;
	char	**str;

	str = ft_split(s, '=');
	if (!str[0])
	{
		free_arr(str);
		return (1);
	}
	tmp = m->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, str[0], ft_strlen(str[0])) == 0)
		{
			free_arr(str);
			return (0);
		}
		tmp = tmp->next;
	}
	free_arr(str);
	return (1);
}
