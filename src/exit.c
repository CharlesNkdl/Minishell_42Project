/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 02:30:05 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/23 22:39:26 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	ft_str_isdigit(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_exittwo(t_data *m, char **s, int i)
{
	i = ft_atoi(s[1]);
	if (i < 0)
		i *= -1;
	if (s[2])
	{
		free_arr(s);
		if (m->pid == 0)
		{
			ft_freem(m, 0);
			ft_putendl_fd("bash: exit: too many arguments", STDERR_FILENO);
			exit(127);
		}
		m->exit_status = 127;
		ft_putendl_fd("exit\nbash: exit: too many arguments", STDERR_FILENO);
		return ;
	}
	else
	{
		free_arr(s);
		ft_freem(m, 0);
		exit(i % 256);
	}
}

void	ft_exit(t_data *m, t_token *tok)
{
	char	**s;
	t_token	*tmp;

	tmp = tok;
	s = ft_split(tmp->content, ' ');
	if (!s[1])
	{
		free_arr(s);
		ft_freem(m, 0);
		exit(0);
	}
	else if (ft_str_isdigit(s[1]) == 1)
		ft_exittwo(m, s, 0);
	else
	{
		ft_freem(m, 0);
		ft_putstr_fd("bash : exit : ", STDERR_FILENO);
		ft_putstr_fd(s[1], 2);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		free_arr(s);
		exit(2);
	}
}
