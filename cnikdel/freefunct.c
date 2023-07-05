#include "../inc/minishell.h"

void	free_tok(t_list **bucket)
{
	t_list	*tmp;

	if (!bucket || !(*bucket))
		return ;
	while (*bucket)
	{
		tmp = (*bucket)->next;
		free(*bucket);
		*bucket = tmp;
	}
	*bucket = NULL;
}

void	**ft_free(char **tabl, int i)
{
	int	j;

	j = 0;
	while (j < i && tabl[j])
	{
		free(tabl[j]);
		j++;
	}
	free(tabl);
	return (0);
}
