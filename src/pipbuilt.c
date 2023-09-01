/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipbuilt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:49:42 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/24 21:49:43 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int	ft_cdpip(t_data *m, t_token *tmp)
{
	char	**s;

	s = ft_split(tmp->content, ' ');
	if (s[1])
	{
		if (chdir(s[1]) == 0)
		{
			free_arr(s);
			ft_freem(m, 0);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free_arr(s);
			perror(tmp->content);
			ft_freem(m, 0);
			exit(EXIT_FAILURE);
		}
	}
	free_arr(s);
	ft_freem(m, 0);
	exit(EXIT_FAILURE);
}

void	ft_exportpip(t_data *m, t_token *tok)
{
	if (ft_strcmp(tok->content, "export") == 0)
		ft_export_solo(m);
	else
		ft_do_export(m, tok);
	ft_freem(m, 0);
	exit(EXIT_SUCCESS);
}

void	ft_full_unsetpip(t_data *m, t_token *supr)
{
	char	**s;
	int		i;

	i = 1;
	s = ft_split(supr->content, ' ');
	while (s[i])
	{
		if (ft_verif_unset(s[i], m) == 0)
			ft_unset(m, s[i]);
		else
		{
			perror(supr->content);
			ft_freem(m, 0);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free_arr(s);
	ft_freem(m, 0);
	exit(EXIT_SUCCESS);
}
