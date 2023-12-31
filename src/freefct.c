/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:25:39 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:25:41 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	**ft_free(char **tabl, int i)
{
	int	j;

	j = 0;
	while (j < i && tabl[j])
	{
		free(tabl[j]);
		j++;
	}
	free(tabl);
	return (0);
}

void	free_arr(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
	{
		return ;
	}
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	freetok(t_token *m)
{
	t_token	*tmp;

	while (m)
	{
		tmp = m;
		if (m->content)
			free(m->content);
		m->content = NULL;
		m = m->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	freeenv(t_env *m)
{
	t_env	*tmp;

	while (m)
	{
		tmp = m;
		if (m->content)
			free(m->content);
		m->content = NULL;
		free(m->key);
		m->key = NULL;
		m = m->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_freem(t_data *m, int i)
{
	if (m->line)
		free(m->line);
	m->line = NULL;
	if (i == 0 && m->env)
	{
		close(m->std[0]);
		close(m->std[1]);
		rl_on_new_line();
		rl_clear_history();
		free_arr(m->env1);
		m->env1 = NULL;
		freeenv(m->env);
		m->env = NULL;
	}
	if (m->token)
		freetok(m->token);
	m->token = NULL;
}
