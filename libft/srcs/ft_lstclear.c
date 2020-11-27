/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:35:45 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:08:11 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr_lst;
	t_list *tmp;

	ptr_lst = *lst;
	while (ptr_lst)
	{
		tmp = ptr_lst->next;
		del(ptr_lst->content);
		free(ptr_lst);
		ptr_lst = tmp;
	}
	*lst = NULL;
}
