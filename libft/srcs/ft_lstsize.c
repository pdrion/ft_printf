/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:16:32 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:14:18 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	tmp = NULL;
	i = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}
