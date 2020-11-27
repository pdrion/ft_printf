/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:37:51 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:10:58 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*n;

	new_list = NULL;
	while (lst)
	{
		if (!(n = ft_lstnew(f(lst->content))))
			ft_lstdelone(lst, del);
		else
			ft_lstadd_back(&new_list, n);
		lst = lst->next;
	}
	return (new_list);
}
