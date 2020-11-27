/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:48:29 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:45:59 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && c1[i] != '\0' && c2[i] != '\0')
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else
		return (c1[i] - c2[i]);
}
