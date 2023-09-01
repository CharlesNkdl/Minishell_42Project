/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:27:08 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:27:09 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

char	*ft_jointok(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len + 2);
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = ' ';
	len = i;
	while (s2 && s2[i - len])
	{
		new[i] = s2[i - len];
		i++;
	}
	new[i] = 0;
	return (new);
}

int	translate_error(t_token *tmp2, t_data *m)
{
	m->exit_status = 69;
	write(STDERR_FILENO, "syntax error near unexpected token `", 36);
	if (tmp2)
	{
		if (tmp2->c == REREDIRL)
			write(STDERR_FILENO, "<<", 2);
		else if (tmp2->c == REREDIRR)
			write(STDERR_FILENO, ">>", 2);
		else if (tmp2->c == WORD)
			write(STDERR_FILENO, tmp2->content, ft_strlenmini(tmp2->content));
		else
			write(STDERR_FILENO, &tmp2->c, 1);
	}
	else
		write(STDERR_FILENO, "newline", 7);
	write(STDERR_FILENO, "'\n", 2);
	return (-1);
}

int	redir(t_token *tmp, t_token *tmp2, t_data *m)
{
	if (!tmp2 || tmp2->c != WORD)
		return (translate_error(tmp2, m));
	tmp->content = tmp2->content;
	tmp->next = tmp2->next;
	free(tmp2);
	tmp2 = NULL;
	return (0);
}

void	commande(t_token *tmp, t_token *tmp2)
{
	char	*tmp3;

	while (tmp2 && tmp2->c == WORD)
	{
		tmp3 = ft_jointok(tmp->content, tmp2->content);
		free(tmp2->content);
		free(tmp->content);
		tmp->content = tmp3;
		tmp->next = tmp2->next;
		free(tmp2);
		tmp2 = tmp->next;
	}
}

void	ft_translator(t_data *m, int i)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = m->token;
	if (tmp->c == PIP)
		i = translate_error(tmp->next, m);
	while (tmp && i == 0)
	{
		tmp2 = tmp->next;
		if (tmp->c == REDIRR || tmp->c == REREDIRL || tmp->c == REDIRL
			|| tmp->c == REREDIRR)
			i = redir(tmp, tmp2, m);
		else if (tmp->c == PIP)
			i = pipo(tmp2, m);
		else
			commande(tmp, tmp2);
		tmp = tmp->next;
	}
	if (i == 0)
		execution(m, 0, m->token);
}
