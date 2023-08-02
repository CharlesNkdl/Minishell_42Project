#include "../inc/minishellnew.h"

void	ft_check_parameters(t_data *m, int i)
{
	while (i > -1 && m->line[i])
	{
		if (m->line[i] == MONEY)
			i = ft_money(m, i + 1, 0);
		else if (m->line[i] == '"')
			i = ft_dquote(m, i + 1);
		else if (m->line[i] == '\'')
			i = ft_quote(m, i + 1);
		else if (m->line[i] == REDIRR || m->line[i] == REDIRL)
			i = ft_redir(m, i);
		else if (m->line[i] == PIP)
			i = ft_pipe(m, i + 1);
		else
			i = ft_word(m, i);
	}
}


void	ft_init_tokens(t_data *m, int in, int out)
{
	char *tmp;

	tmp = ft_strtrim(m->line, " ");
	free(m->line);
	m->line = tmp;
	m->token = NULL;
	m->heredoc = 0;
	m->pid = -1;
	m->fd[0] = -1;
	m->fd[1] = -1;
	m->std[0] = in;
	m->std[1] = out;
	ft_check_parameters(m, 0);
}

void	ft_begin(t_data *m)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	m->exit_status = 0;
	m->env = ft_envnode(m->env1);
	m->line = NULL;
	while (in > 0 && out > 0)
	{
		m->line = readline("prompt > ");
		if (!m->line)
			return ;
		if (ft_strlen(m->line) > 0)
		{
			add_history(m->line);
			ft_init_tokens(m, in, out);
			if (m->token)
				ft_translator(m, 0);
			ft_freem(m, 1);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data m;

	(void)argv;
	if (argc == 1)
	{
		m.env1 = strdbldup(envp);
		ft_begin(&m);
		rl_redisplay();
		write(1, "exit\n", 5);
		ft_freem(&m, 0);
	}
	return (0);
}
