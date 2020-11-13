/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:39:07 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/13 20:54:18 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

//Gestion du %s
void   ft_printf_str(va_list *my_list, int isneg, int space)
{
		if (isneg < -1)
			ft_putspaces(space);
		
		char *src = va_arg(*my_list, char *);
		ft_putstr(src);
}

//Gestion du %c
void ft_printf_char(va_list *my_list, int isneg, int space)
{
	
	char c =  va_arg(*my_list, int);
		if (isneg == 0)
			{
				ft_putspaces(space);
				ft_putchar(c);
			}
		else
			{
				ft_putchar(c);
				ft_putspaces(space);
			}
}

//Gestion du %d
void ft_printf_nbr(va_list *my_list, int isneg, int space)
{
	int num = va_arg(*my_list, int);
	if (isneg == 1)
		ft_putchar('-');					
		ft_putnbr(num);
	ft_putspaces(space);
}

//Gestion du %u
void ft_printf_nbru(va_list *my_list, int isneg, int space)
{
	unsigned int num = (unsigned int)va_arg(*my_list, int);
	if (isneg != -1)
		{
			ft_putnbr(num);
		}
		ft_putspaces(space);
	
}

//Gestion du %p
void ft_printf_adress(va_list *my_list, int isneg, int space)
{
	int i;
	uintptr_t p = (uintptr_t)va_arg(*my_list, void *);
	if (isneg != -1)
		{
	i=sizeof(p) << 3;
	i = i-20;
	printf("sizeof de p : %lu\n",sizeof(p) );
	printf("size de i : %d\n",i );
	ft_putchar('0');
	ft_putchar('x');
	
	while(i>=0)
	{
		ft_putchar(hex_digit((p >> i) & 0xf));
		i -= 4;
	}
	ft_putspaces(space);
		}
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
	s_flag->precision = '\0'; //number after .
	s_flag->size = '\0'; //lhjz
	s_flag->len = 0;
}

int ft_parser(const char *src , t_flag * s_flagdef)
{
	int i;
	int tmpindex;

	spec_mask = "cspdiuxX%";
	conversion_mask = "-0.*";
	precision_mask ="lljjjd";

	i = 0;
	//   printf("au moment ou il rentre src = %s\n", src);
	//	 printf("au moment ou il rentre spec MASK = %s\n", spec_mask);
	//printf("au moment ou il rentre STRINDEX = %d\n",ft_strindex(spec_mask, *src + i));
	//printf("le caractere est  = %c\n\n",spec_mask[ft_strindex(spec_mask, *src + i)]);

	while (i <= 10)
		{
			printf("src [%d] = %c\n", i, src[i]);
			if((tmpindex = ft_strindex(&conversion_mask[0], src[i])) != -1)
				{
					printf("tmpIndex pour la conversion = %d\n", tmpindex);
					s_flagdef->conversion = conversion_mask[tmpindex];
					printf("le pointeur sur conversion contient : %c\n", s_flagdef->conversion);
				}
				while (src[i] >= '0' && src[i] <= '9')
					{
						s_flagdef->width = s_flagdef->width * 10 + (src[i] - 48);
						printf("width : %d\n", s_flagdef->width);
						i++;
					}
			if((tmpindex = ft_strindex(spec_mask, src[i])) != -1)
				{
					s_flagdef->specifier = spec_mask[tmpindex];
					printf("le pointeur sur specifier contient : %c\n", s_flagdef->specifier);
					return (i);//le nombre de caracteres lu pour passer
				}
			i++;
		}
	return (0);//le nombre de caracteres lu pour passer
}

//Fonction ft_Printf
int ft_printf(const char *src, ...)
{
	t_flag *s_flagdef;  //strcuture pour les tags
	
	//void (*tabFunction[6])(va_list *, int, int) =
	//	{
	//	 ft_printf_str,
	//	 ft_printf_char,
	//	 ft_printf_nbr,
	//	 ft_printf_nbr,
	//	 ft_printf_nbru,
	//	 ft_printf_adress
	//	};
	//char tabIndex[7] = {'s', 'c', 'd', 'i', 'u',  'p', 0};
	va_list my_list;
	int i;
	int tmpi;
	//int space;
	//int tmpIndex;
	//int isneg;
	
	va_start(my_list, src);

	if (!(s_flagdef = (t_flag*)malloc(sizeof(t_flag))))
		return (-1);
	
	i = 0;
	tmpi = 0;
	//space = 0;
	//tmpIndex = 0;
	//isneg = 0;

	while (src[i] != 0)
		{	
		if(i != 0 && src[i - 1] == '%')
				{
					ft_structinitialize(s_flagdef);
					if((tmpi = ft_parser(&src[i], s_flagdef)) != -1)
						i = i + tmpi;
					printf("tmpi : %d\n", tmpi);
					   
					   //if(src[i] == '-')
					   //{
					   //	 isneg = 1;
					   // i++;
					   //}

					   //if(ft_isdigit(src[i])==1)
					   //{
					   //	space = src[i] - 48;
					   //i++;
					   //}
					
					   //tmpIndex = findIndex(tabIndex, src[i]);
					   //if(tmpIndex != -1)
					   //{
					   //	(*tabFunction[tmpIndex]) (&my_list, isneg, space);
					   //}
				}
		//else if (src[i] != '%')
			//{
		//write(1, &src[i], 1);
				//	}
				
		i++;
		//		space = 0;
		//isneg = 0;
		}
	free(s_flagdef);
	return(0);
}
