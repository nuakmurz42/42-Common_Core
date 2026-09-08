/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuakmurz <nuakmurz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:34:53 by nuakmurz          #+#    #+#             */
/*   Updated: 2026/06/27 17:23:55 by nuakmurz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*list_helper;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		list_helper = ft_lstnew(f(lst->content));
		if (!list_helper)
			return (ft_lstclear(&new_list, del), NULL);
		ft_lstadd_back(&new_list, list_helper);
		lst = lst->next;
	}
	return (new_list);
}
