/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:19:30 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/19 21:01:02 by pdrion           ###   ########.fr       */
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
	
	if (!src)
		src = "(null)";
	if (s_flag->precision == -1 || (size_t)s_flag->precision >= ft_strlen(src))
		len = ft_strlen(src);
	else
		len =s_flag->precision;
	ft_printf_str(src, len, s_flag);
}

//Gestion du %d
void	ft_printf_d(va_list *my_list, t_flag * s_flag)
{
	//int num = va_arg(*my_list, int);
	int num = va_arg(*my_list, int);
	char *src;
	//	int isneg;


	s_flag->isneg = ft_isneg(num, s_flag);
	if (s_flag->isneg)
		num = -num;	
	
	src = (num == 0 && s_flag->precision == 0)? "" : ft_itoa(num);
	ft_printf_nbr(src, s_flag);
}

//Gestion du %u
//void ft_printf_u(va_list *my_list, t_flag * s_flag)
//{

	//unsigned int num = (unsigned int)va_arg(*my_list, int);
	
	//	ft_putnbr(num);
	//ft_putspaces(s_flag->width, s_flag->formatspecifier);
	
//}

//Gestion du %p
void	ft_printf_p(va_list *my_list, t_flag * s_flag)
{
	int i;
	uintptr_t p = (uintptr_t)va_arg(*my_list, void *);
	
	i = sizeof(p) << 3;
	//i = i-20;
	//printf("sizeof de p : %lu\n",sizeof(p) );
	//printf("size de i : %d\n",i );
	ft_putchar('0', s_flag);
	ft_putchar('x', s_flag);
	
	while(i>=0)
	{
		ft_putchar(hex_digit((p >> i) & 0xf), s_flag);
		i -= 4;
	}
	ft_putformat(s_flag->width, s_flag->formatspecifier, s_flag);
}

//Fonction ft_Printf
int		ft_printf(const char *src, ...)
{
	t_flag *s_flag;  //strcuture pour les tags
	
	void (*tabFunction[5])(va_list *, t_flag *) =
		{
		 ft_printf_c,
		 ft_printf_s,
		 ft_printf_p,	
		 ft_printf_d,
		 //		 ft_printf_i,
		 //		 ft_printf_u,
		 //		 ft_printf_x,
		 //		 ft_printf_X,
		};
	va_list my_list;
	int i;
	int tmpi;

	va_start(my_list, src);
	if (!(s_flag = (t_flag*)malloc(sizeof(t_flag))))
		return (-1);
	
	i = 0;
	tmpi = 0;
	ft_structinitialize(s_flag);
	while (src[i] != 0) 
 	{	 
 		if(i != 0 && src[i - 1] == '%') 
 		{ 
 			ft_structreset(s_flag); 
 			if((tmpi = ft_parser(&src[i], s_flag, &my_list)) != -1) 
 			{ 
 				i = i + tmpi; 
 				(*tabFunction[ft_strindex(s_flag->spec_mask, src[i])]) (&my_list, s_flag); 
 			}
 		}
 		else if (src[i] != '%' && src[i]!='\0') 
 			ft_putchar(src[i], s_flag); 
 		i++; 
 	} 
 	tmpi = s_flag->len;
	free(s_flag);
	return(tmpi);
}
