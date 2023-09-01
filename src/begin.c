/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:26:11 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:26:13 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

int		g_sigvar = 0;

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
	if (i == -11)
	{
		write(STDERR_FILENO, "Quotes not closed(42  Minishell special)\n", 42);
		ft_freem(m, 1);
		return ;
	}
}

char	*check_last_pipe(char *str)
{
	int		i;
	int		check;
	char	*buf;
	char	*result;

	i = -1;
	buf = NULL;
	check = 0;
	while (str[++i])
	{
		if (str[i] == '|')
			check = 1;
		if (check == 1 && ft_isalnum(str[i]))
			check = 0;
	}
	if (check == 1 && g_sigvar == 0)
	{
		buf = readline("> ");
		result = ft_strjoin(str, buf);
		free(buf);
		free(str);
		return (check_last_pipe(result));
	}
	else
		return (str);
}

void	ft_work(t_data *m, int in, int out)
{
	m->line = check_last_pipe(m->line);
	add_history(m->line);
	ft_init_tokens(m, in, out);
	if (m->token)
		ft_translator(m, 0);
	ft_freem(m, 1);
}

void	*ft_begin(t_data *m)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	m->env = ft_envnode(m->env1);
	m->line = NULL;
	ft_inifir(m, in, out);
	while (in > 0 && out > 0)
	{
		init_signals(0);
		g_sigvar = 0;
		m->line = readline("prompt > ");
		if (!m->line)
			return (NULL);
		if (ft_strlen(m->line) > 0)
			ft_work(m, in, out);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	m;

	(void)argv;
	g_sigvar = 0;
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
