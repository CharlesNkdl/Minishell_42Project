/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dircheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:22 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:26:23 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	dirstattwo(t_data *m, char *s, int i, struct stat path_stat)
{
	if (S_ISDIR(path_stat.st_mode))
	{
		write(STDERR_FILENO, s, ft_strlen(s));
		write(STDERR_FILENO, ": is a directory\n", 17);
		if (i < 0)
			free(s);
		ft_freem(m, 0);
		exit(126);
	}
	else if (!S_ISREG(path_stat.st_mode))
	{
		perror(s);
		if (i < 0)
			free(s);
		ft_freem(m, 0);
		exit(127);
	}
	if (i < 0)
		free(s);
}

void	dirstat(t_data *m, char *s, int i)
{
	struct stat	path_stat;

	if (stat(s, &path_stat))
	{
		perror(s);
		if (i < 0)
			free(s);
		ft_freem(m, 0);
		exit(126);
	}
	dirstattwo(m, s, i, path_stat);
}

void	verifdir(t_data *m, char *s, int i)
{
	if (*s == '.' || *s == '/')
	{
		if (s[1] == '.' && s[2] == '\0')
		{
			write(STDERR_FILENO, s, ft_strlen(s));
			write(STDERR_FILENO, ": command not found\n", 20);
			ft_freem(m, 0);
			exit(127);
		}
		else if (!s[1])
		{
			write(STDERR_FILENO, ".: usage: . filename [arguments]\n", 33);
			ft_freem(m, 0);
			exit(2);
		}
		while (s[i] && s[i] != ' ')
			i++;
		if (s[i])
		{
			s = ft_substr(s, 0, i);
			i = -1;
		}
		dirstat(m, s, i);
	}
}
