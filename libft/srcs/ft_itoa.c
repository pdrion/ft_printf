/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:18:51 by pdrion            #+#    #+#             */
/*   Updated: 2019/11/30 22:04:58 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				len;
	char			*result;

	result = NULL;
	len = (n <= 0 ? 1 : 0);
	nb = (n < 0 ? -n : n);
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	if (!(result = malloc(sizeof(char) * len + 1)))
		return (NULL);
	result[len--] = '\0';
	nb = (n < 0 ? -n : n);
	while (len)
	{
		result[len--] = nb % 10 + 48;
		nb = nb / 10;
	}
	result[0] = (n < 0 ? '-' : nb + 48);
	return (result);
}
