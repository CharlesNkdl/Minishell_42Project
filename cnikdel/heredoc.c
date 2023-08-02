#include "../inc/minishellnew.h"

void	enfantdoc(int in, char *s2)
{
	char	*s;

	s = readline("> ");
	if (s)
	{
		while (ft_strncmp(s, s2, ft_strlen(s)) && s)
		{
			write(in, s, ft_strlen(s));
			write(in, "\n", 1);
			free(s);
			s = readline("> ");
		}
		if (s)
			free(s);
	}
	exit(0);
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
		return (- 1);
	}
	if (pid == 0)
		enfantdoc(in, s2);
	waitpid(pid, 0, 0);
	close(in);
	return (0);
}
