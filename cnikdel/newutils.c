#include "../inc/minishellnew.h"

char **strdbldup(char **str)
{
	int count;
	char **copy;
	int i;

	count = -1;
	i = -1;
	while (str[++count])
		count++;
	copy = (char **)malloc((count + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (++i < count)
	{
		copy[i] = ft_strdup(str[i]);
		if (!copy[i])
		{
			ft_free(copy, i);
			return (NULL);
		}
	}
	copy[count] = NULL;
	return (copy);
}

