/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:03:17 by llaigle           #+#    #+#             */
/*   Updated: 2023/08/23 21:55:58 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	ft_env(t_data *m)
{
	t_env	*temp;

	temp = m->env;
	while (temp)
	{
		ft_putstr_fd(temp->key, m->out);
		ft_putchar_fd('=', m->out);
		ft_putendl_fd(temp->content, m->out);
		temp = temp->next;
	}
	ft_freem(m, 0);
	exit(EXIT_SUCCESS);
}
