/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:29:33 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 16:30:33 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	char			*s;

	i = 0;
	d = dst;
	s = (char *)src;
	while (i < n && (i == 0 || s[i - 1] != (char)c))
	{
		d[i] = s[i];
		i++;
	}
	if (i > 0 && s[i - 1] == (char)c)
		return (d + i);
	else
		return (NULL);
}
