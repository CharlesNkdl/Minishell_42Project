/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:31:02 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/24 03:27:07 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	ft_cd(t_data *m, t_token *tmp)
{
	char	**s;

	s = ft_split(tmp->content, ' ');
	if (s[1])
	{
		if (chdir(s[1]) == 0)
		{
			free_arr(s);
			m->exit_status = 0;
			return (0);
		}
		else
		{
			free_arr(s);
			perror(tmp->content);
			m->exit_status = 1;
			return (0);
		}
	}
	else
	{
		free_arr(s);
		m->exit_status = 1;
	}
	return (0);
}
