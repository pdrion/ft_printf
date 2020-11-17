/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:34:05 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/15 18:49:50 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_parser(const char *src , t_flag * s_flagdef, va_list *my_list)
{
	int i;
	int tmpindex;

	i = 0;
	while (s_flagdef->specifier == '\0' && src[i] != '\0')
		{
				if((tmpindex = ft_strindex(s_flagdef->conversion_mask, src[i])) != -1)
					{
						s_flagdef->conversion = s_flagdef->conversion_mask[tmpindex];
						i++;
					}	
				else if (src[i] >= '0' && src[i] <= '9')
					{
						while (src[i] >= '0' && src[i] <= '9')
							s_flagdef->width = s_flagdef->width * 10 + (src[i++] - 48);						
					}
				else if (src[i]== '.')
					{
						i++;
						s_flagdef->precision = 0;
						if (src[i]== '*')
							s_flagdef->precision = va_arg(*my_list, int);
						while (src[i] >= '0' && src[i] <= '9')
							s_flagdef->precision = s_flagdef->precision * 10 + (src[i++] - 48);		
				}
				else if((tmpindex = ft_strindex(s_flagdef->spec_mask, src[i])) != -1 && src[i] != '\0')
					{
						s_flagdef->specifier = s_flagdef->spec_mask[tmpindex];
						if (s_flagdef->conversion == '0'&& s_flagdef->precision == -1 )
							s_flagdef->formatspecifier  = '0';
						return (i);//le nombre de caracteres lu pour passer
					}
				else
					i++;
		}
	return (-1);//le nombre de caracteres lu pour passer
}
