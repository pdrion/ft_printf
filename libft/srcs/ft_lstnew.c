/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:13:47 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:12:18 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;
	t_list	*n;

	list = NULL;
	n = NULL;
	if (!(n = malloc(sizeof(t_list))))
		return (NULL);
	n->content = content;
	n->next = NULL;
	list = n;
	return (list);
}
