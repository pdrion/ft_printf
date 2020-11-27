/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:44:01 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:35:46 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*src;

	ch = (char)c;
	src = (char *)s;
	while (*src != '\0')
	{
		if (*src == ch)
			return (src);
		src++;
	}
	if (ch == '\0')
		return (src);
	return (NULL);
}
