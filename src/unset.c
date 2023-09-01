/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:04:46 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/24 03:18:31 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

void	ft_unset(t_data *m, char *supr)
{
	t_env	*temp;
	t_env	*previous;

	temp = m->env;
	previous = NULL;
	while (temp)
	{
		if (ft_strncmp(temp->key, supr, ft_strlen(supr)) == 0)
		{
			if (previous == NULL)
				m->env = temp->next;
			else
				previous->next = temp->next;
			free(temp->content);
			free(temp->key);
			free(temp);
			return ;
		}
		else
		{
			previous = temp;
			temp = temp->next;
		}
	}
}

int	ft_verif_unset(char *s, t_data *m)
{
	t_env	*tmp;

	tmp = m->env;
	while (tmp)
	{
		if (ft_strncmp(s, tmp->key, ft_strlen(s)) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_full_unset(t_data *m, t_token *supr)
{
	char	**s;
	int		i;

	i = 1;
	s = ft_split(supr->content, ' ');
	while (s[i])
	{
		if (ft_verif_unset(s[i], m) == 0)
			ft_unset(m, s[i]);
		i++;
	}
	free_arr(s);
	ft_envdd(m, 0);
	return ;
}
