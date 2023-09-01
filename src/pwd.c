/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:03:34 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/23 22:40:38 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	ft_pwd(t_data *m)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
	{
		ft_putendl_fd(cwd, m->out);
		ft_freem(m, 0);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_freem(m, 0);
		perror("Pwd");
		exit(EXIT_FAILURE);
	}
}
