/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:27:00 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:27:01 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

char	**strdbldup(char **str)
{
	int		count;
	char	**copy;
	int		i;

	count = -1;
	i = -1;
	while (str[++count])
		count = count + 1 - 1;
	copy = (char **)malloc((count + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (++i < count)
	{
		copy[i] = ft_strdup(str[i]);
		if (!copy[i])
		{
			ft_free(copy, i);
			return (NULL);
		}
	}
	copy[count] = NULL;
	return (copy);
}

int	ft_strlenmini(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

int	pipo(t_token *tmp2, t_data *m)
{
	if (!tmp2 || tmp2->c == PIP)
		return (translate_error(tmp2, m));
	return (0);
}
