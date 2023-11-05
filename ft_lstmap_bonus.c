/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:15:06 by zelabbas          #+#    #+#             */
/*   Updated: 2023/11/04 16:25:45 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nodes;
	t_list	*temp;

	if (!lst || !del || !f)
		return (NULL);
	nodes = NULL;
	temp = NULL;
	while (lst)
	{
		temp = ft_lstnew(NULL);
		if (!temp)
		{
			ft_lstclear(&nodes, del);
			return (NULL);
		}
		temp->content = f(lst->content);
		ft_lstadd_back(&nodes, temp);
		lst = lst->next;
	}
	return (nodes);
}
