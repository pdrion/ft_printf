/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:39:07 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/15 19:14:36 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


//Gestion du %c
void ft_printf_char(va_list *my_list, t_flag * s_flagdef)
{
	char c =  va_arg(*my_list, int);
		if (s_flagdef->conversion == '-')
			{
				ft_putchar(c);
				ft_putspaces(s_flagdef->width - 1, s_flagdef->formatspecifier);
			}
		else
			{
				ft_putspaces(s_flagdef->width - 1, s_flagdef->formatspecifier);
				ft_putchar(c);
			}
		s_flagdef->len = s_flagdef->len + s_flagdef->width +1;
}

//Gestion du %s
void   ft_printf_str(va_list *my_list, t_flag * s_flagdef)
{
		char *src = va_arg(*my_list, char *);
		int len;

		if (!src)
			src = "(null)";

		len =  (s_flagdef->precision == -1 || (size_t)s_flagdef->precision >= ft_strlen(src)) ? ft_strlen(src) : s_flagdef->precision;
		if (s_flagdef->conversion == '-')
			{
				ft_putstrlen(src,len);
				ft_putspaces(s_flagdef->width - len, s_flagdef->formatspecifier);	
			}
		else 
			{
				ft_putspaces(s_flagdef->width - len, s_flagdef->formatspecifier);
				ft_putstrlen(src, len);
			}
		s_flagdef->len = s_flagdef->len + ft_strlen(src);
}



//Gestion du %d
void ft_printf_nbr(va_list *my_list, t_flag * s_flagdef)
{
	//int num = va_arg(*my_list, int);
	int num = va_arg(*my_list, int);
	char *src;
	int len;
	int isneg;

	len = 0;
	isneg = 0;
	if (num < 0)
		{
		isneg = 1;
	num = -num;	
		}
	
	src = (num == 0 && s_flagdef->precision == 0)? "" : ft_itoa(num);

	if (!src)
		src = "(null)";

	len =  (s_flagdef->precision < 0 || (size_t)s_flagdef->precision <= ft_strlen(src)) ? ft_strlen(src) : s_flagdef->precision;
	len = len + isneg;
	//printf("formatspecifier = %c\nFlag de conversion = %c\nisneg = %d\n\n" ,s_flagdef->formatspecifier,s_flagdef->conversion, isneg);
	
	if (s_flagdef->conversion == '-')
		{
			if (isneg == 1)
				ft_putchar('-');
			ft_putspaces(s_flagdef->precision - ft_strlen(src), '0');	
			ft_putstrlen(src,len);
			ft_putspaces(s_flagdef->width - len, s_flagdef->formatspecifier);	
		}
	else 
		{
			if (s_flagdef->formatspecifier == '0')
				{
					if (isneg == 1)
						ft_putchar('-');
					ft_putspaces(s_flagdef->width - len, s_flagdef->formatspecifier);			
				}
			else
				{
					ft_putspaces(s_flagdef->width - len, s_flagdef->formatspecifier);
						if (isneg == 1)
							ft_putchar('-');
				}

			
				ft_putspaces(s_flagdef->precision - ft_strlen(src), '0');	
			ft_putstrlen(src, len);
		}
}

//Gestion du %u
void ft_printf_nbru(va_list *my_list, t_flag * s_flagdef)
{
	unsigned int num = (unsigned int)va_arg(*my_list, int);
	
	ft_putnbr(num);
	ft_putspaces(s_flagdef->width, s_flagdef->formatspecifier);
	
}

//Gestion du %p
void ft_printf_adress(va_list *my_list, t_flag * s_flagdef)
{
	int i;
	uintptr_t p = (uintptr_t)va_arg(*my_list, void *);
	
	i=sizeof(p) << 3;
	//i = i-20;
	//printf("sizeof de p : %lu\n",sizeof(p) );
	//printf("size de i : %d\n",i );
	ft_putchar('0');
	ft_putchar('x');
	
	while(i>=0)
	{
		ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
	}
	ft_putspaces(s_flagdef->width, s_flagdef->formatspecifier);
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


//*************FONCTION PARSER*********************
//tester si il  y a un specifirer
	//tester si il  y a une largeur, et si il y a une largeur,
    //il faut connaitre la bon chiffre (itoa)
	//tester si il y a une precision
	// si il ya une precision quel en est la largeur (itoa)
	// tester le type

void ft_structinitialize(t_flag * s_flag)
{
	s_flag->specifier = '\0'; //csd...
	s_flag->conversion = '\0'; //-+ 0#
	s_flag->width = '\0'; //width of printed char
	s_flag->precision = -1; //number after .
	s_flag->size = '\0'; //lhjz
	s_flag->formatspecifier = ' ';//format specifier default ' ';
}


//Fonction ft_Printf
int ft_printf(const char *src, ...)
{
	t_flag *s_flagdef;  //strcuture pour les tags
	
	void (*tabFunction[6])(va_list *, t_flag *) =
		{
		 ft_printf_char,
		 ft_printf_str,
		 ft_printf_adress,	
		 ft_printf_nbr,
		 ft_printf_nbr,
		 ft_printf_nbru,
		};
	va_list my_list;
	int i;
	int tmpi;
	
	va_start(my_list, src);

	if (!(s_flagdef = (t_flag*)malloc(sizeof(t_flag))))
		return (-1);
	
	i = 0;
	tmpi = 0;
	s_flagdef->spec_mask = "cspdiuxX";
	s_flagdef->conversion_mask = "-0#+";
	s_flagdef->size_mask ="lljjjd";

	while (src[i] != 0)
		{	
		if(i != 0 && src[i - 1] == '%')
			{
				ft_structinitialize(s_flagdef);
				if((tmpi = ft_parser(&src[i], s_flagdef, &my_list)) != -1)
					{
						i = i + tmpi;
						(*tabFunction[ft_strindex(s_flagdef->spec_mask, src[i])]) (&my_list, s_flagdef);
					}
			}
		else if (src[i] != '%' && src[i]!='\0')
			write(1, &src[i], 1);
		i++;
		}
	free(s_flagdef);
	return(0);
}
