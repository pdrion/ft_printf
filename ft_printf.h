/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:25:25 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/15 18:10:47 by pdrion           ###   ########.fr       */
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
	char * spec_mask;
	char * conversion_mask;
	char * size_mask;
	char specifier; //csd...
	char formatspecifier; // ' ' or '0'
	char conversion; //-+ 0#
	int width; //width of printed char
	int precision; //number after .
	int size; //lhjz
	int len; //return value of printf
}t_flag;

	



void    ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putstrlen(char *s, int len);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_isascii(char c);
int		ft_isdigit(int c);
char hex_digit(int v);
void    ft_putspaces(int space, char c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

int ft_strindex(char *tab, char element);
int ft_parser(const char *src , t_flag * s_flagdef, va_list *my_list);

void ft_printf_str(va_list *my_list, t_flag * s_flagdef);
void ft_printf_char(va_list *my_list, t_flag * s_flagdef);
void ft_printf_nbr(va_list *my_list, t_flag * s_flagdef);
void ft_printf_nbru(va_list *my_list, t_flag * s_flagdef);
void ft_printf_adress(va_list *my_list, t_flag * s_flagdef);
int findIndex(char *tab, char element);

int     ft_printf(const char *src, ...);
#endif
