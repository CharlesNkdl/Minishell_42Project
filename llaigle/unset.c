

void    ft_unset(t_minishell *env, char *supr)
{
    int i;
    size_t len;

    len = ft_strlen(supr);
    i = 0;
    while(env->envp[i])
    {
        if(ft_strlcmp(env->envp[i], supr, len) != 0) //0 = argument a supprimer trouvé
            i++;
        else
        {
            free(env->envp[i]);
            while(env->envp[i])
            {
                env->envp[i] = env->envp[i + 1];
                i++;
            }
            env->envp[i] = NULL;
        }
    }
}

