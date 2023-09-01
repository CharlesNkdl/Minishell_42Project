/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:50:26 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/24 21:50:27 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

t_env	*initee(char **str)
{
	t_env	*newnode;

	newnode = NULL;
	newnode = malloc(sizeof(t_env));
	if (!newnode)
		return (NULL);
	newnode->key = ft_strdup(str[0]);
	return (newnode);
}

t_data	*ft_gugugaga(char *s, t_data *m)
{
	t_env	*tmp;
	t_env	*tmp2;
	t_env	*newnode;
	char	**str;

	tmp = m->env;
	tmp2 = m->env;
	if (tmp->next)
		tmp2 = tmp->next;
	str = ft_split(s, '=');
	newnode = initee(str);
	if (str[1])
		newnode->content = ft_strdup(str[1]);
	else
	{
		free(newnode->key);
		free(newnode);
		free_arr(str);
		return (m);
	}
	newnode->next = NULL;
	ft_ntr(str, tmp2, tmp, newnode);
	return (m);
}

void	*ft_ntr(char **str, t_env *tmp2, t_env *tmp, t_env *newnode)
{
	while (tmp2)
	{
		if (ft_strcmp(str[1], tmp2->content) < 0)
		{
			newnode->next = tmp2;
			tmp->next = newnode;
			free_arr(str);
			return (0);
		}
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	free_arr(str);
	return (0);
}

void	ft_change_content(char **s, t_data *m)
{
	char	**str;
	t_env	*tmp;

	tmp = m->env;
	str = ft_split(s[1], '=');
	while (tmp)
	{
		if (ft_strncmp(str[0], tmp->key, ft_strlen(str[0])) == 0)
		{
			if (tmp->content)
			{
				free(tmp->content);
				tmp->content = NULL;
			}
			if (str[1])
				tmp->content = ft_strdup(str[1]);
			free_arr(str);
			return ;
		}
		else
			tmp = tmp->next;
	}
	free_arr(str);
	return ;
}

int	ft_verif_export(char *s)
{
	if (ft_strchr(s, '=') != 0)
		return (1);
	return (0);
}
