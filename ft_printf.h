/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:25:25 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/13 16:14:37 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
#include <string.h> //TO REMOOOOOOOVE
#include <stdint.h>


typedef struct	s_flag{
	char specifier; //csd...
	char conversion; //-+ 0#
	int width; //width of printed char
	int precision; //number after .
	int size; //lhjz
	int len; //return value of printf
}t_flag;

	char * spec_mask;
	char * conversion_mask;
	char * precision_mask;



void    ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_isascii(char c);
int		ft_isdigit(int c);
char hex_digit(int v);
void    ft_putspaces(int space);
int		ft_atoi(const char *str);

void ft_printf_str(va_list *my_list, int isneg, int space);
void ft_printf_char(va_list *my_list, int isneg, int space);
void ft_printf_nbr(va_list *my_list, int isneg, int space);
void ft_printf_nbru(va_list *my_list, int isneg, int space);
void ft_printf_adress(va_list *my_list, int isneg, int space);
int findIndex(char *tab, char element);

int     ft_printf(const char *src, ...);
#endif
