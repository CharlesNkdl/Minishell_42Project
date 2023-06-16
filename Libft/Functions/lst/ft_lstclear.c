/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:42:45 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:42:46 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*repli;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		repli = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = repli;
	}
	*lst = NULL;
}
