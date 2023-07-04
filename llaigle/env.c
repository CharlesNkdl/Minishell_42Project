
void		ft_env(t_minishell *env)
{
    int i;

    i = 0;
	while (env->envp[i])
	{
		ft_printf("%s\n"env->envp[i]);
		i++;
	}
}