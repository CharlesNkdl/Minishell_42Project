/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefctwo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:25:46 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:25:48 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	cmdfree(char *tmp, char **tmp1)
{
	int	i;

	i = 0;
	if (tmp)
		free(tmp);
	if (!tmp1)
		return ;
	while (tmp1[i])
	{
		free(tmp1[i]);
		i++;
	}
	free(tmp1);
}
