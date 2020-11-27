/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:24:24 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/27 23:57:21 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isneg(int num, t_flag * s_flag)
{
	if (num < 0)
	{
		s_flag->isneg = 1;
		s_flag->signspecifier = '-';
		return (1);
			}
	return(0);
}

int ft_strindex(char *tab, char element)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

char 	*ft_convert_base(int base_len, long int nbr, char *base, char * result)
{
	char  *s1;

	s1 = NULL;
	if (!(s1 = malloc(sizeof(char) + 1)))
		return (NULL);
	s1[1] = '\0';
	if (nbr)
	{
		result = ft_convert_base(base_len, nbr / base_len, base, result);
		*s1 = base[nbr % base_len];
		result = ft_strjoin(result, s1);
	}
	free(s1);
	return (result);
}
