/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_initialize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:35:13 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/27 23:59:15 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_structinitialize(t_flag * s_flag)
{
	s_flag->spec_mask = "cspdiuxX%";
	s_flag->conversion_mask = "-+ 0#";
	s_flag->size_mask ="lljjjd";
	s_flag->len = 0,
	ft_structreset(s_flag);
}

void ft_structreset(t_flag * s_flag)
{
	s_flag->specifier = '\0'; //csd...
	s_flag->conversion = '\0'; //-+ 0#
	s_flag->signspecifier = '\0';
	s_flag->width = '\0'; //width of printed char
	s_flag->precision = '\0'; //number after .
	s_flag->size = '\0'; //lhjz
	s_flag->formatspecifier = ' ';//format specifier default ' ';
	s_flag->isneg = 0;
}
