/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:19 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/27 18:32:14 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"




void	ft_printf_nbr_conversion_neg()
{
	
}



void	ft_printf_nbr(char *src, t_flag * s_flag)
{
	int len;
	len = 0;

	if (!src)
		src = "(null)";

	len = (s_flag->precision < 0 || (size_t)s_flag->precision <= ft_strlen(src)) ? ft_strlen(src) : s_flag->precision;
	len = (s_flag->signspecifier == '\0') ? len : len + 1;
	if (s_flag->conversion == '-')
	{
		if (s_flag->signspecifier != '\0')
			ft_putchar(s_flag->signspecifier, s_flag);
		ft_putformat(s_flag->precision - ft_strlen(src), '0', s_flag);	
		ft_putstrlen(src,len, s_flag);
		ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);	
	}
	else 
	{
		if (s_flag->formatspecifier == '0')
		{
			if (s_flag->signspecifier != '\0')
				ft_putchar(s_flag->signspecifier, s_flag);
			ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);			
		}
		else
		{
			ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);
			if (s_flag->signspecifier != '\0')
				ft_putchar(s_flag->signspecifier, s_flag);
		}
		ft_putformat(s_flag->precision - ft_strlen(src), '0', s_flag);	
		ft_putstrlen(src, len, s_flag);
	}
}
