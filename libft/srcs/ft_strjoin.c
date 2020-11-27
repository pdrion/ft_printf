/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:14:27 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:38:26 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(result = (char*)malloc(sizeof(*result) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1 != '\0')
		result[i++] = *s1++;
	while (*s2 != '\0')
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}
