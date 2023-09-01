/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaigle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:40 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/24 03:31:30 by llaigle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	enfantdoc(t_data *m, int in, char *s2)
{
	char	*s;

	s = readline("> ");
	if (s)
	{
		while (ft_strncmp(s, s2, ft_strlen(s) + 1) && s && g_sigvar == 0)
		{
			write(in, s, ft_strlen(s));
			write(in, "\n", 1);
			free(s);
			if (g_sigvar != 0)
			{
				ft_freem(m, 0);
				exit(0);
			}
			s = readline("> ");
		}
		if (s)
			free(s);
	}
	ft_freem(m, 0);
	exit(0);
}

int	heredoctwo(t_data *m, char *s2, int in, int pid)
{
	if (pid == 0)
	{
		init_signals(2);
		enfantdoc(m, in, s2);
	}
	else
	{
		init_signals(1);
		waitpid(pid, 0, 0);
	}
	init_signals(0);
	close(in);
	return (0);
}

int	heredoc(char *s2, t_data *m, int in)
{
	pid_t	pid;
	char	*s;
	char	*s3;

	s3 = ft_itoa(m->heredoc++);
	s = ft_strjoin("heredoc.tmp", s3);
	free(s3);
	in = open(s, O_RDWR | O_CREAT | O_TRUNC, 0644);
	free(s);
	if (in < 0)
		return (in);
	pid = fork();
	if (pid < 0)
	{
		perror(0);
		ft_freem(m, 1);
		return (-1);
	}
	return (heredoctwo(m, s2, in, pid));
}
