/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnikdel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:43:40 by cnikdel           #+#    #+#             */
/*   Updated: 2023/04/11 11:43:42 by cnikdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*check;

	if (!lst || !f || !del)
		return (NULL);
	cpy = 0;
	while (lst)
	{
		check = ft_lstnew(f(lst->content));
		if (!check)
		{
			ft_lstclear(&cpy, del);
			return (NULL);
		}
		ft_lstadd_back(&cpy, check);
		lst = lst->next;
	}
	return (cpy);
}
