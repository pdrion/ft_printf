/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:39:07 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/11 23:08:58 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

//Gestion du %s
void   ft_printf_str(va_list *my_list)
{
	char *src = va_arg(*my_list, char *);
	ft_putstr(src);
}

//Gestion du %c
void ft_printf_char(va_list *my_list)
{
	char c =  va_arg(*my_list, int);
	//if (ft_isascii(c) != 0)
		ft_putchar(c);
}

//Gestion du %d
void ft_printf_nbr(va_list *my_list)
{
	int num = va_arg(*my_list, int);
	ft_putnbr(num);
}

//Gestion du %u
void ft_printf_nbru(va_list *my_list)
{
	unsigned int num = (unsigned int)va_arg(*my_list, int);
	ft_putnbr(num);
}

//Gestion du %p
void ft_printf_adress(va_list *my_list)
{
	int i;
	uintptr_t p = (uintptr_t)va_arg(*my_list, void *);

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
}

int findIndex(char *tab, char element)
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

//Fonction ft_Printf
int ft_printf(const char *src, ...)
{
	void (*tabFunction[6])(va_list *) =
		{
		 ft_printf_str,
		 ft_printf_char,
		 ft_printf_nbr,
		 ft_printf_nbr,
		 ft_printf_nbru,
		 ft_printf_adress
		};
	char tabIndex[7] = {'s', 'c', 'd', 'i', 'u',  'p', 0};
	va_list my_list;
	int i;
	int tmpIndex;
	
	va_start(my_list, src);
	i = 0;
	tmpIndex = 0;

	while (src[i] != 0)
		{
		if(i != 0 && src[i - 1] == '%')
				{
					tmpIndex = findIndex(tabIndex, src[i]);
					if(tmpIndex != -1)
						{
							(*tabFunction[tmpIndex]) (&my_list);
						}
				}
			else if (src[i] != '%')
				{
				write(1, &src[i], 1);
				}
			i++;
		}
	return(0);
}
