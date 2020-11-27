/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:49:45 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:40:05 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t size_src;
	size_t size_new;

	if (src == NULL)
		return (0);
	size_src = ft_strlen(src);
	size_new = 0;
	if (dstsize == 0)
		return (size_src);
	if (size_src >= dstsize)
		size_new = dstsize - 1;
	else
		size_new = size_src;
	ft_memcpy(dst, src, size_new);
	dst[size_new] = '\0';
	return (size_src);
}
