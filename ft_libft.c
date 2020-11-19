/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:24:24 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/18 12:16:55 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isneg(int num, t_flag * s_flag)
{
	if (num < 0)
	{
		return (1);
		s_flag->isneg = 1;
	}
	return(0);
}

int		ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char hex_digit(int v)
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here	
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
