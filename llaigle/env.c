
void		ft_env(t_minishell **env)
{
    int     i;

    i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}