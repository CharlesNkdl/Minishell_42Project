/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdhandling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:26 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:26:27 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

char	*cmdjoin(char *tmp, int i)
{
	char	*s;

	s = NULL;
	if (!tmp)
		return (NULL);
	if (i == 0)
	{
		while (tmp[i] && tmp[i] != ' ')
			i++;
		if (!tmp[i])
			return (tmp);
		return (ft_substr(tmp, 0, i));
	}
	while (*tmp)
	{
		if (*tmp == '/')
			s = tmp;
		tmp++;
	}
	if (s && *s)
		s++;
	return (s);
}

char	*cmdadd(t_token *tmp, t_env *env)
{
	t_bez	b;

	b.new = NULL;
	b.i = 0;
	while (env && ft_strncmp(env->key, "PATH", 4) != 0)
		env = env->next;
	if (!env)
		return (NULL);
	b.tmp1 = ft_split(env->content, ':');
	b.tmp3 = ft_split(tmp->content, ' ');
	b.tmp2 = ft_strjoin("/", b.tmp3[0]);
	b.tmp4 = ft_strjoin(b.tmp1[b.i], b.tmp2);
	while (b.tmp1 && access(b.tmp4, X_OK) == -1 && b.tmp1[b.i])
	{
		if (b.tmp4)
			free(b.tmp4);
		b.i++;
		b.tmp4 = ft_strjoin(b.tmp1[b.i], b.tmp2);
	}
	if (b.tmp1 && b.tmp1[b.i])
		b.new = ft_strjoin(b.tmp1[b.i], b.tmp2);
	cmdfree(b.tmp4, b.tmp3);
	cmdfree(b.tmp2, b.tmp1);
	return (b.new);
}
