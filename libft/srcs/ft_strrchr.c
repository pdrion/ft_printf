/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:45:41 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 23:05:26 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*src;
	char	*pos;
	int		i;

	ch = (char)c;
	src = (char *)s;
	pos = NULL;
	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == ch)
			pos = &src[i];
		i++;
	}
	if (ch == '\0')
		return (&src[i]);
	return (pos);
}
