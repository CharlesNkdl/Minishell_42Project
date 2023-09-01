/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execsolobuilt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:50:05 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/24 21:50:07 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	checkbuiltstwo(t_data *m, t_token *tmp)
{
	if (ft_strncmp(tmp->content, "cd", 2) == 0)
	{
		ft_cd(m, tmp);
		return (1);
	}
	else if (ft_strncmp(tmp->content, "export", 6) == 0)
	{
		ft_export(m, tmp);
		return (1);
	}
	else if (ft_strncmp(tmp->content, "exit", 4) == 0)
	{
		ft_exit(m, tmp);
		return (1);
	}
	else
		return (0);
}

int	checkbuilts(t_data *m)
{
	t_token	*tmp;

	tmp = m->token;
	while (tmp->next)
	{
		if (tmp->c == PIP)
			return (0);
		tmp = tmp->next;
	}
	tmp = m->token;
	if (ft_strncmp(tmp->content, "unset", 5) == 0)
	{
		ft_full_unset(m, tmp);
		return (1);
	}
	return (checkbuiltstwo(m, tmp));
}
