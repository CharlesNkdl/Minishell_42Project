/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:25:21 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:25:22 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	accessor(char *s)
{
	char	*tmp;
	int		i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	if (s[i])
	{
		tmp = ft_substr(s, 0, i);
		if (access(tmp, X_OK) != -1)
		{
			free(tmp);
			return (0);
		}
	}
	return (-1);
}

int	accessperm(char *s, char c)
{
	int	i;

	i = -1;
	if (c == '<')
	{
		if (access(s, F_OK) == 0 && access(s, R_OK) == 0)
			i = open(s, O_RDONLY);
		else
			perror(s);
	}
	else
	{
		if (c == '>')
			i = open(s, O_RDWR | O_CREAT | O_TRUNC, 0644);
		else
			i = open(s, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (access(s, F_OK) != 0 || (access(s, R_OK) != 0 && access(s,
					W_OK) != 0))
			perror(s);
	}
	return (i);
}

int	heredocread(int i, t_data *m)
{
	char	*s;
	char	*tmp;

	tmp = ft_itoa(m->heredoc++);
	s = ft_strjoin("heredoc.tmp", tmp);
	free(tmp);
	if (i != -1 && access(s, F_OK) == 0 && access(s, R_OK) == 0)
		i = open(s, O_RDONLY);
	else if (i != -1)
		perror(s);
	unlink(s);
	free(s);
	return (i);
}
