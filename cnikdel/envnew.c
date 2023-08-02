#include "../inc/minishellnew.h"

t_env	*ft_new_env(char *s)
{
	t_env	*new;
	int	i;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	new->key = ft_substr(s, 0, i);
	new->content = ft_strdup(s + i + 1);
	new->next = NULL;
	return (new);
}

t_env	*ft_envnode(char **envp)
{
	t_env	*env;
	t_env	*tmp;
	t_env	*tmp2;
	int		i;

	i = 0;
	env = NULL;
	tmp2 = NULL;
	while (envp[i])
	{
		tmp = ft_new_env(envp[i]);
		//SECURITE ET FREE LE ENV
		if (!env)
			env = tmp;
		else
			tmp2->next = tmp;
		tmp2 = tmp;
		i++;
	}
	return (env);

}
