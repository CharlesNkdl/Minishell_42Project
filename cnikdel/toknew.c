#include "../inc/minishellnew.h"

char	*ft_moneysub(t_data *m, int i, int j)
{
	char	*tmp;
	t_env	*tmpenv;

	if(!m->env)
		return (NULL);
	tmp = ft_substr(m->line, i, j);
	tmpenv = m->env;
	while (tmpenv)
	{
		if (!ft_strncmp(tmp, tmpenv->key, ft_strlen(tmp)))
		{
			free(tmp);
			return (ft_strdup(tmpenv->content));
		}
		tmpenv = tmpenv->next;
	}
	free(tmp);
	return (NULL);
}

int ft_money(t_data *m, int i, int j)
{
	if (!m->line[i] || ft_symbol(m->line[i]) > 2 || m->line[i] == MONEY || nextok(m, REREDIRL))
	{
		ft_addt(m, WORD, ft_substr(m->line, i-1, 1), 1);
		return (i);
	}
	if (m->line[i] == '?' || ft_isdigit(m->line[i]))
	{
		if (m->line[i] == '?')
			ft_addt(m, WORD, ft_itoa(m->exit_status), 1);
		else
		{
			if (m->line[i] == '0')
				ft_addt(m, WORD, ft_strdup("bash"), 1);
			else
				ft_addt(m, WORD, ft_strdup(""), 1);
		}
		i++;
		return (i);
	}
	while (ft_symbol(m->line[i + j]) == 0 && m->line[i + j] != MONEY  && m->line[i + j] != '/')
		j++;
	ft_addt(m, WORD, ft_moneysub(m, i ,j), 1);
	return (i + j);
}

int ft_dquote(t_data *m, int i)
{
	int	j;

	j = 0;
	while (m->line[i + j] && m->line[i + j] != '"')
	{
		if (m->line[i + j] == MONEY && m->line[i + j + 1] != '"')
		{
			if (j > 0)
				ft_addt(m, WORD, ft_substr(m->line, i, j), 1);
			i = ft_money(m, i + j + 1, 0);
			j = - 1;
		}
		j++;
	}
	// METTRE SECURITE LA AUSSI genre si la guillement est pas ferme
	ft_addt(m, WORD, ft_substr(m->line, i , j), 1);
	return (i + j + 1);
}

int ft_quote(t_data *m, int i)
{
	int	j;

	j = 0;
	while (m->line[i + j] && m->line[i + j] != '\'')
		j++;
	// METTRE SECURITE LA MAIS LA FLEMME
	ft_addt(m, WORD, ft_substr(m->line, i, j), 1);
	return (i + j + 1);
}

int ft_redir(t_data *m, int i)
{
	ft_splitok(m);
	if (m->line[i] == REDIRL)
	{
		i++;
		if (m->line[i] == REDIRL)
		{
			i++;
			ft_addt(m, REREDIRL, NULL, 0);
		}
		else
			ft_addt(m, REDIRL, NULL, 0);
	}
	else
	{
		i++;
		if (m->line[i] == REDIRR)
		{
			i++;
			ft_addt(m, REREDIRR, NULL, 0);
		}
		else
			ft_addt(m, REDIRR, NULL, 0);
	}
	return (i);
}

int ft_pipe(t_data *m, int i)
{
	ft_splitok(m);
	ft_addt(m, PIP, NULL, 0);
	return (i);
}

int ft_word(t_data *m, int i)
{
	if (m->line[i] == ' ' || m->line[i] == '\v' || m->line[i] == '\t')
	{
		ft_splitok(m);
		while (m->line[i] == ' ' || m->line[i] == '\v' || m->line[i] == '\t')
			i++;
		return (i);
	}
	ft_addt(m, WORD, ft_substr(m->line, i, 1), 1);
	return (i + 1);
}
