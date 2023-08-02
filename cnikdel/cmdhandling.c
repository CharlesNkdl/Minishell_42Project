#include "../inc/minishellnew.h"

char	*cmdjoin(char *tmp, int	i)
{
	char	*s;

	s = NULL;
	if (!tmp)
		return (NULL);
	if (i == 0)
	{
		while (tmp[i] && tmp[i] != ' ')
			i++;
		if (!tmp[i])
			return (tmp);
		return (ft_substr(tmp, 0, i));
	}
	while (*tmp)
	{
		if (*tmp == '/')
			s = tmp;
		tmp++;
	}
	if (s && *s)
		s++;
	return (s);
}

char	*cmdadd(t_token *tmp, t_env *env)
{
	char	*new;
	char	*tmp2;
	char	**tmp1;
	int		i;

	new = NULL;
	i = 0;
	while (env && ft_strncmp(env->key, "PATH", 4) != 0)
		env = env->next;
	if (!env)
		return (NULL);
	tmp1 = ft_split(env->content, ':');
	tmp2 = ft_strjoin("/", *ft_split(tmp->content, ' '));
	while (tmp1 && access(ft_strjoin(tmp1[i], tmp2), X_OK) == -1 && tmp1[i])
		i++;
	if (tmp1 && tmp1[i])
		new = ft_strjoin(tmp1[i], tmp2);
	cmdfree(tmp2, tmp1);
	return (new);
}
