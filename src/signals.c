/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:25:52 by cnikdel           #+#    #+#             */
/*   Updated: 2023/08/22 22:25:53 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishellnew.h"

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_sigvar = 50;
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		g_sigvar = 50;
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_heredoc(int sig)
{
	g_sigvar = 50;
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	init_signals(int boule)
{
	if (boule == 0)
	{
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (boule == 1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (boule == 2)
	{
		signal(SIGINT, signal_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (boule == 3)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}
