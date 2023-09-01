/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childtwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:49:48 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/24 21:49:50 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	reset_init(t_exc *args)
{
	if (args->argv)
	{
		free_arr(args->argv);
		args->argv = NULL;
	}
	if (args->path)
	{
		free(args->path);
		args->path = NULL;
	}
	else
		args->path = NULL;
}

void	exc_init(t_data *m, t_token *tmp, t_exc *args, int mode)
{
	char	**str;

	str = NULL;
	if (mode == 0)
	{
		str = ft_split(tmp->content, ' ');
		args->path = ft_strdup(str[0]);
		args->argv = strdbldup(str);
		free_arr(str);
		args->envp = m->env1;
	}
	else if (mode == 1)
	{
		reset_init(args);
		args->path = cmdadd(tmp, m->env);
		args->argv = ft_split(tmp->content, ' ');
		args->envp = m->env1;
	}
}
