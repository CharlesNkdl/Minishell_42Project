/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 01:30:10 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/23 22:40:32 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	ft_builtins(t_data *m, t_token *tmp)
{
	if (ft_strncmp(tmp->content, "echo", 4) == 0)
		ft_echo(m, tmp);
	else if (ft_strncmp(tmp->content, "env", 3) == 0)
		ft_env(m);
	else if (ft_strncmp(tmp->content, "pwd", 3) == 0)
		ft_pwd(m);
	else if (ft_strncmp(tmp->content, "unset", 5) == 0)
		ft_full_unsetpip(m, tmp);
	else if (ft_strncmp(tmp->content, "cd", 2) == 0)
		ft_cdpip(m, tmp);
	else if (ft_strncmp(tmp->content, "export", 6) == 0)
		ft_exportpip(m, tmp);
	else if (ft_strncmp(tmp->content, "exit", 4) == 0)
		ft_exit(m, tmp);
	else
		enfantexectwo(m, tmp);
}
