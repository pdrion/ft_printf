/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:11:28 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:36:44 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = NULL;
	if ((dst = (char *)malloc(ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1));
	dst[ft_strlen(s1)] = '\0';
	return (dst);
}
