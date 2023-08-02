#include "../inc/minishellnew.h"

void	dirstat(char *s, int i)
{
	struct stat	path_stat;

	stat(s, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		write(2, s, ft_strlen(s));
		write(2, ": is a directory\n", 17);
		if (i < 0)
			free(s);
		exit(126);
	}
	else if (!S_ISREG(path_stat.st_mode))
	{
		perror(s);
		if (i < 0)
			free(s);
		exit(127);
	}
	if (i < 0)
		free(s);
}

void	verifdir(char *s, int i)
{
	if (*s == '.' || *s == '/')
	{
		if (s[1] == '.' && s[2] == '\0')
		{
			write(2, s, ft_strlen(s));
			write(2, ": command not found\n", 20);
			exit(127);
		}
		else if (!s[1])
		{
			write(2, ".: usage: . filename [arguments]\n", 33);
			exit(2);
		}
		while (s[i] && s[i] != ' ')
			i++;
		if (s[i])
		{
			s = ft_substr(s, 0, i);
			i = -1;
		}
		dirstat(s, i);
	}
}
