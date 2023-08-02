#include "../inc/minishellnew.h"

void	execfour(t_data *m, t_token *tmp, int i)
{
	m->pid = fork();
	if (m->pid < 0)
	{
		perror("fork");
		ft_freem(m, 1);
		return ;
	}
	if (m->pid == 0)
		enfantexec(m, tmp, i);
	if (i)
	{
		close(m->fd[1]);
		if (i > 0)
			dup2(m->fd[0], 0);
		else
			dup2(m->std[0], 0);
		close(m->fd[0]);
	}
}

void	execthree(t_data *m, t_token *tmp, int i)
{
	t_token *tmp2;

	tmp2 = tmp;
	while (tmp2 && tmp2->c != PIP)
		tmp2 = tmp2->next;
	if (tmp2)
		i++;
	else if (!tmp2 && i > 0)
		i = i * -1;
	if (i > 0)
	{
		if (pipe(m->fd) == -1)
		{
			perror("pipe");
			ft_freem(m, 1);
			return ;
		}
	}
	execfour(m, tmp, i);
}

t_token	*exectwo(t_data *m, t_token *tmp, int i)
{
	int	j;

	j = 0;
	m->in = 0;
	m->out = 1;
	tmp = exredir(m, tmp, 0, 0);
	while (!j && tmp)
	{
		if (m->in > -1 && m->out > - 1 && tmp->c == WORD)
			execthree(m, tmp, i);
		else if (tmp && tmp->c == PIP)
			j = 1;
		tmp = tmp->next;
	}
	return (tmp);
}

void	execution(t_data *m, int i, t_token *tmp)
{
	while (tmp)
	{
		if (tmp->c == REREDIRL)
			if (heredoc(tmp->content, m, 0))
				return ;
		tmp = tmp->next;
	}
	m->heredoc = 0;
	tmp = m->token;
	while (tmp)
	{
		tmp = exectwo(m, tmp, i);
		i++;
	}
	enfants(m, i);
}
