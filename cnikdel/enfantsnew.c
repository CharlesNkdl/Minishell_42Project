#include "../inc/minishellnew.h"

void	enfantexecthree(t_data *m, t_token *tmp)
{
	if (m->env && cmdadd(tmp, m->env) != NULL)
	{
		if (execve(cmdadd(tmp, m->env), ft_split(tmp->content, ' '), m->env1) == -1)
		{
			perror(tmp->content);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(2, tmp->content, ft_strlen(tmp->content));
		write(2, ": command not found\n", 20);
		exit(127);
	}
}

void	enfantexectwo(t_data *m, t_token *tmp)
{
	if (accessor(tmp->content) != -1)
	{
		if (execve(cmdjoin(tmp->content, 0), ft_split(cmdjoin(tmp->content, 1), ' '), m->env1) == -1)
		{
			perror(tmp->content);
			exit(EXIT_FAILURE);
		}
	}
	else
		enfantexecthree(m, tmp);
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
	verifdir(tmp->content, 0);
	enfantexectwo(m, tmp);
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
		while (wait(NULL) > 0)
			m->heredoc = 0;
	}
	dup2(m->std[0], 0);
	dup2(m->std[1], 1);
}
