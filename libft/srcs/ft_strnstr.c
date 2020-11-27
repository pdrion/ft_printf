/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:51:36 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:49:14 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	cmp;
	unsigned int	i;

	i = 0;
	cmp = 0;
	if (needle[cmp] == '\0')
		return ((char *)haystack);
	while (haystack[i] && len--)
	{
		cmp = 0;
		while (haystack[i + cmp] != '\0' && haystack[i + cmp]
				== needle[cmp] && len + 1 - cmp)
		{
			if (needle[cmp + 1] == '\0')
				return ((char *)haystack + i);
			cmp++;
		}
		i++;
	}
	return (NULL);
}
