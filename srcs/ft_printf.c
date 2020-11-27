/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:19:30 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/27 14:23:32 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Gestion du %c
void	ft_printf_c(va_list *my_list, t_flag * s_flag)
{
	char c =  va_arg(*my_list, int);
	if (s_flag->conversion == '-')
	{
		ft_putchar(c, s_flag);
		ft_putformat(s_flag->width - 1, s_flag->formatspecifier, s_flag);
	}
	else
	{
		ft_putformat(s_flag->width - 1, s_flag->formatspecifier, s_flag);
		ft_putchar(c, s_flag);
	}
}

//Gestion du %s
void	ft_printf_s(va_list *my_list, t_flag * s_flag)
{
	char *src = va_arg(*my_list, char *);
	int len;

	len = 0;
	if (!src)
	{
		if (!(src = malloc(sizeof(char) * 7)))
			return;
		src = "(null)";
	}
	if (s_flag->precision <= -1 || (size_t)s_flag->precision >= ft_strlen(src))
		len = ft_strlen(src);
	else
		len = s_flag->precision;
	ft_printf_str(src, len, s_flag);
}

//Gestion du %d
void	ft_printf_d(va_list *my_list, t_flag * s_flag)
{
	int num = va_arg(*my_list, int);
	char *src;

	s_flag->isneg = ft_isneg(num, s_flag);
	if (s_flag->isneg)
		num = -num;
	src = (num == 0 && s_flag->precision == 0)? "" : ft_itoa((unsigned int)num);
	ft_printf_nbr(src, s_flag);
}

//Gestion du %i
void	ft_printf_i(va_list *my_list, t_flag * s_flag)
{
	int num = va_arg(*my_list, int);
	char *src;

	s_flag->isneg = ft_isneg(num, s_flag);
	if (s_flag->isneg)
		num = -num;	
	src = (num == 0 && s_flag->precision == 0)? "" : ft_itoa((unsigned int)num);
	ft_printf_nbr(src, s_flag);
}

//Gestion du %u
void	ft_printf_u(va_list *my_list, t_flag * s_flag)
{
	unsigned int num = va_arg(*my_list, unsigned int);
	char *src;
	src = (num == 0 && s_flag->precision == 0)? "" : ft_itoa(num);
	ft_printf_nbr(src, s_flag);
}

void	ft_printf_x(va_list *my_list, t_flag * s_flag)
{
	unsigned int num = (unsigned int)va_arg(*my_list, unsigned int);
	char *src;
	char *resultconversion;

	if (!(resultconversion = malloc(sizeof(char))))
			return;
	*resultconversion = '\0';
	if (num == 0 &&  s_flag->precision != 0)
		src = "0";
	else
		src = (s_flag->precision == 0)? "" : ft_convert_base(16, num, "0123456789abcdef", resultconversion);
	ft_printf_nbr(src, s_flag);
}

//Gestion du %X
void	ft_printf_X(va_list *my_list, t_flag * s_flag)
{
	unsigned int num = va_arg(*my_list, unsigned int);
	char *src;
	char *resultconversion;

		if (!(resultconversion = malloc(sizeof(char))))
			return;
	*resultconversion = '\0';
	if (num == 0 &&  s_flag->precision != 0)
		src = "0";
	else
		src = (s_flag->precision == 0)? "" : ft_convert_base(16, num, "0123456789ABCDEF", resultconversion);
	ft_printf_nbr(src, s_flag);
}

//Gestion du %p
void	ft_printf_p(va_list *my_list, t_flag * s_flag)
{
	long int num = (long int)va_arg(*my_list, void *);
	int i;
	char *src;
	char *resultconversion;

	i = 0;
	resultconversion = NULL;
	if (!(resultconversion = malloc(sizeof(char))))
			return;
resultconversion[0] = '\0';
	if (num == 0 &&  s_flag->precision != 0)
		src = "0";
	else
		src = ft_convert_base(16, num, "0123456789abcdef", resultconversion);
	i = s_flag->precision - ft_strlen(src);
	s_flag->precision = 0;
	if (!(resultconversion = malloc(sizeof(char)*3)))
			return;
	resultconversion[0] = '0';
	resultconversion[1] = 'x';
	resultconversion[2] = '\0';
	while( i-- > 0)
		resultconversion =  ft_strjoin(resultconversion, "0");
	src = ft_strjoin(resultconversion, src);
	ft_printf_nbr(src, s_flag);
	free (resultconversion);
}


//Gestion du %p
void	ft_printf_pct(va_list *my_list, t_flag * s_flag)
{

	char *src = va_arg(*my_list, char *);
	int len;

	len =0;
	src = "%";
	if (s_flag->precision <= -1 || (size_t)s_flag->precision >= ft_strlen(src))
		len = ft_strlen(src);
	else
		len = s_flag->precision;
	ft_printf_str(src, len, s_flag);
}

//Fonction ft_Printf_Handler
void	ft_printf_handler(va_list *my_list, int index, t_flag * s_flag)
{
	void (*tabFunction[9])(va_list *, t_flag *) =
		{
		 ft_printf_c,
		 ft_printf_s,
		 ft_printf_p,	
		 ft_printf_d,
		 ft_printf_i,
		 ft_printf_u,
		 ft_printf_x,
		 ft_printf_X,
		  ft_printf_pct,
		};
	(*tabFunction[index]) (my_list, s_flag); 
}

void	ft_printf_loop(va_list *my_list, const char *src, t_flag * s_flag)
{
	int i;
	int tmpi;

	i = 0;
	tmpi = 0;
	while (src[i] != 0) 
 	{
		if(i != 0 && src[i - 1] == '%' && s_flag->specifier != '%') 
 		{
 			ft_structreset(s_flag); 
 			if((tmpi = ft_parser(&src[i], s_flag, my_list)) != -1) 
 			{
 				i = i + tmpi;
				if (src[i] != '\0')
				{
					//	if (ft_strindex(s_flag->spec_mask, src[i]) == '%')
					//	ft_printf_pct(s_flag);
					//else
						ft_printf_handler(my_list, ft_strindex(s_flag->spec_mask, src[i]), s_flag);
				}
 			}
 		}
 		else if (src[i] != '%' && src[i]!='\0') 
 			ft_putchar(src[i], s_flag); 
 		i++; 
 	} 
}

int		ft_printf(const char *src, ...)
{
	t_flag *s_flag;  //strcuture pour les tags
	va_list my_list;
	int tmp;

	tmp = 0;
	va_start(my_list, src);
	if (!(s_flag = (t_flag*)malloc(sizeof(t_flag))))
		return (-1);
	ft_structinitialize(s_flag);
	ft_printf_loop(&my_list, src, s_flag);
	tmp = s_flag->len;
	free(s_flag);
	return(tmp);
}
