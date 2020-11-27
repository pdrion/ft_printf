/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:34:05 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/28 00:00:47 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser_conversion(const char * src, t_flag * s_flag)
{
	int tmpindex;

	tmpindex=0;
	if((tmpindex = ft_strindex(s_flag->conversion_mask, *src)) != -1)
	{
		if (s_flag->conversion_mask[tmpindex] == '+')
			s_flag->signspecifier = '+';
		else if (!(s_flag->conversion_mask[tmpindex] == '0' && s_flag->conversion == '-'))
			s_flag->conversion = s_flag->conversion_mask[tmpindex];
	}	
}

void	ft_parser_width(const char * src, t_flag * s_flag, va_list *my_list)
{
	
	if (s_flag->precision == -1)
	{
		if (*src == '*')
		{
			s_flag->width = va_arg(*my_list, int);
			s_flag->conversion = (s_flag->width <0) ? '-' : s_flag->conversion;
			s_flag->width = (s_flag->width <0) ? -s_flag->width : s_flag->width;
		}	
		else
		{
			while (*src >= '0' && *src <= '9')
			s_flag->width = s_flag->width * 10 + (*src++ - 48);
		}
	}
}

void	ft_parser_precision(const char * src, t_flag * s_flag, va_list *my_list)
{
	if (*src == '.')
	{
		src++;
		s_flag->precision = 0;
		if (*src == '*')
		{
			s_flag->precision = va_arg(*my_list, int);
			s_flag->precision = (s_flag->precision<0) ? -2 : s_flag->precision;
		}
		else
		{
			while (*src >= '0' && *src <= '9')
			s_flag->precision = s_flag->precision * 10 + (*src++ - 48);					
		}
	}
}

void	ft_parser_spec(const char * src, t_flag * s_flag)
{
	int tmpindex;
		tmpindex=0;
	if((tmpindex = ft_strindex(s_flag->spec_mask, *src)) != -1 && *src != '\0')
	{
		s_flag->specifier = s_flag->spec_mask[tmpindex];
		if (s_flag->conversion == '0' && s_flag->precision == -1)
			s_flag->formatspecifier  = -1;


	}
}

void ft_debug(t_flag * s_flag)
{
	printf("conversion : %c\n" , s_flag->conversion);
	printf("width : %d\n" , s_flag->width);
	printf("precision : %d\n" , s_flag->precision);
	printf("specifier : %c\n" , s_flag->specifier);
	printf("format specifier : %c\n" , s_flag->formatspecifier);	
	printf("isneg : %d\n" , s_flag->isneg);
		
}

int ft_parser(const char *src , t_flag * s_flag, va_list *my_list)
{
	int i;
	i= 0;
	
	while (s_flag->specifier == '\0' && src[i] != '\0')
	{
		ft_parser_conversion(src + i, s_flag);
		ft_parser_width(src + i, s_flag, my_list);
		ft_parser_precision(src + i, s_flag, my_list);
		ft_parser_spec(src + i, s_flag);
		//ft_debug(s_flag);
		if(s_flag->specifier != '\0')
			return (i);
		if (src[i] >= '0' && src[i] <= '9')
		{
			while (src[i] >= '0' && src[i] <= '9')
				i++;
		}
		else
			i++;
	}
	if (src[i] == '\0')
		return(0);
	return(i);
}
