/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:25:25 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/11 22:53:24 by pdrion           ###   ########.fr       */
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

void    ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_isascii(char c);
int		ft_isdigit(int c);
char hex_digit(int v);


void ft_printf_str(va_list *my_list);
void ft_printf_char(va_list *my_list);
void ft_printf_nbr(va_list *my_list);
void ft_printf_nbru(va_list *my_list);
void ft_printf_adress(va_list *my_list);
int findIndex(char *tab, char element);

int     ft_printf(const char *src, ...);
#endif
