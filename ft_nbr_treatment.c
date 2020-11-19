/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:19 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/19 20:12:01 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_printf_nbr(char *src, t_flag * s_flag)
{
	int len;
	len = 0;

	if (!src)
		src = "(null)";

	len =  (s_flag->precision < 0 || (size_t)s_flag->precision <= ft_strlen(src)) ? ft_strlen(src) : s_flag->precision;
	len = len + s_flag->isneg;
	//printf("formatspecifier = %c\nFlag de conversion = %c\nisneg = %d\n\n" ,s_flag->formatspecifier,s_flag->conversion, s_flag->isneg);
	//if (s_flag->precision < s_flag->width)
	//	s_flag->width = 0;
	
	if (s_flag->conversion == '-')
	{
		if (s_flag->isneg == 1)
			ft_putchar('-', s_flag);
		ft_putformat(s_flag->precision - ft_strlen(src), '0', s_flag);	

		ft_putstrlen(src,len, s_flag);
		ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);	
	}
	else 
	{
		if (s_flag->formatspecifier == '0')
		{
			if (s_flag->isneg == 1)
				ft_putchar('-', s_flag);
			ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);			
		}
		else
		{
			ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);
			if (s_flag->isneg == 1)
				ft_putchar('-', s_flag);
		}
		ft_putformat(s_flag->precision - ft_strlen(src), '0', s_flag);	
		ft_putstrlen(src, len, s_flag);
		
	}
}

int		ft_atoi(const char *str)
{
	int i;
	int nb;
	int isneg;

	i = 0;
	nb = 0;
	isneg = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		isneg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	return (isneg * nb);
}
