/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:49:59 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/24 21:50:00 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	ft_llstsize(t_env *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	*ft_envdd(t_data *m, int i)
{
	char	**s;
	t_env	*tmp;
	int		len;
	char	*ss;

	tmp = m->env;
	len = ft_llstsize(tmp);
	s = (char **)malloc(sizeof(char *) * (len + 1));
	if (!s)
		return (NULL);
	ft_memset(s, 0, sizeof(char *) * (len + 1));
	while (tmp)
	{
		ss = ft_strjoin(tmp->key, "=");
		s[i] = ft_strjoin(ss, tmp->content);
		free(ss);
		i++;
		tmp = tmp->next;
	}
	if (m->env1)
		free_arr(m->env1);
	m->env1 = NULL;
	m->env1 = s;
	return (0);
}
