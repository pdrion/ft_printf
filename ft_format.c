/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:41:39 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/18 12:16:04 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putformat(int nbchar, char c, t_flag * s_flag)
{
	if(!c)
		return;
	while(nbchar >= 1)
	{
		ft_putchar(c, s_flag);
		nbchar = nbchar -1;
	}
}
