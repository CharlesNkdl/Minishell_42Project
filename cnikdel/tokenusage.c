#include "../inc/minishell.h"

void	ft_tokenbadd_back(t_token **lst, t_token *new)
{
	t_token	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	ptr = ft_lstlast(*lst);
	ptr->next = new;
}
