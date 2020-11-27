/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:44:51 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/27 18:33:07 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c, t_flag * s_flag)
{
	write(1, &c, 1);
	s_flag->len = s_flag->len + 1;		
}

void	ft_putstr(char *s, t_flag * s_flag)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++, s_flag);
}

void	ft_putstrlen(char *s, int len, t_flag * s_flag)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] && i <= len - 1)
		ft_putchar(s[i++], s_flag);
}

void   ft_printf_str(char *src, int len, t_flag * s_flag)
{
	if (!src)
	{
		if (!(src = malloc(sizeof(char) * 7)))
			return;
		src = "(null)";
	}
		if (s_flag->conversion == '-')
			{
				ft_putstrlen(src, len, s_flag);
				ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);	
			}
		else 
			{
				ft_putformat(s_flag->width - len, s_flag->formatspecifier, s_flag);
				ft_putstrlen(src, len, s_flag);
			}
}
