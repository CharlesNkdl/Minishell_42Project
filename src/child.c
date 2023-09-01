/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:25:27 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:25:28 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	enfantexecthree(t_data *m, t_token *tmp, t_exc args)
{
	exc_init(m, tmp, &args, 1);
	if (m->env && args.path != NULL)
	{
		if (m->env && execve(args.path, args.argv, args.envp) == -1)
		{
			reset_init(&args);
			perror(tmp->content);
			ft_freem(m, 0);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(2, tmp->content, ft_strlen(tmp->content));
		write(2, ": command not found\n", 20);
		reset_init(&args);
		ft_freem(m, 0);
		exit(127);
	}
}

void	enfantexectwo(t_data *m, t_token *tmp)
{
	t_exc	args;

	exc_init(m, tmp, &args, 0);
	if (access(args.path, X_OK) == 0)
	{
		if (execve(args.path, args.argv, args.envp) == -1)
		{
			perror(tmp->content);
			reset_init(&args);
			ft_freem(m, 0);
			exit(EXIT_FAILURE);
		}
	}
	else
		enfantexecthree(m, tmp, args);
	reset_init(&args);
	ft_freem(m, 0);
	exit(0);
}

void	enfantexec(t_data *m, t_token *tmp, int i)
{
	if (m->in != 0)
		dup2(m->in, 0);
	if (m->out != 0)
		dup2(m->out, 1);
	if (i)
	{
		close(m->fd[0]);
		if (m->out == 1 && i > 0)
			dup2(m->fd[1], 1);
		else if (m->out == 1 && i < 0)
			dup2(m->std[1], 1);
		close(m->fd[1]);
	}
	verifdir(m, tmp->content, 0);
	ft_builtins(m, tmp);
}

void	enfants(t_data *m, int i)
{
	if (m->pid >= 0)
	{
		waitpid(m->pid, &i, 0);
		if (WIFSIGNALED(i))
		{
			write(1, "\n", 1);
			m->exit_status = 128 + WTERMSIG(i);
		}
		else if (WIFEXITED(i))
			m->exit_status = WEXITSTATUS(i);
		m->heredoc = 0;
	}
	dup2(m->std[0], 0);
	dup2(m->std[1], 1);
}
