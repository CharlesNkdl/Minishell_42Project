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
