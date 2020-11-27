/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:25:25 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/27 19:42:24 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <string.h> //TO REMOOOOOOOVE
# include <stdint.h>

typedef struct	s_flag{
	char	*spec_mask;
	char	*conversion_mask;
	char	*size_mask;

	char	specifier;			//csd...
	char	formatspecifier;	// ' ' or '0'
	char	signspecifier;		// '-' or '+'
	char	conversion;			//-+ 0#
	int		isneg;				//sign of the number
	int		width;				//width of printed char
	int		precision;			//number after .
	int		size; 				//lhjz
	int		len;				//return value of printf
}				t_flag;

//		ft_printf.c
void	ft_printf_c(va_list *my_list, t_flag * s_flag);
void	ft_printf_s(va_list *my_list, t_flag * s_flag);
void 	ft_printf_p(va_list *my_list, t_flag * s_flag);
void	ft_printf_d(va_list *my_list, t_flag * s_flag);
void	ft_printf_i(va_list *my_list, t_flag * s_flag);
void	ft_printf_u(va_list *my_list, t_flag * s_flag);
void	ft_printf_x(va_list *my_list, t_flag * s_flag);
void	ft_printf_X(va_list *my_list, t_flag * s_flag);
void	ft_printf_handler(va_list *my_list, int index, t_flag * s_flag);
void	ft_printf_loop(va_list *my_list, const char *src, t_flag * s_flag);
int		ft_printf(const char *src, ...);

//		ft_printf_initialize.c
void	ft_structinitialize(t_flag * s_flag);
void	ft_structreset(t_flag * s_flag);

//		ft_format.c
void	ft_putformat(int nbchar, char c, t_flag * s_flag);

//		ft_parser.c
int		ft_parser(const char *src , t_flag * s_flag, va_list *my_list);
void	ft_parser_conversion(const char * src, t_flag * s_flag);
void	ft_parser_width(const char * src, t_flag * s_flag, va_list *my_list);
void	ft_parser_precision(const char * src, t_flag * s_flag, va_list *my_list);
void	ft_parser_spec(const char * src, t_flag * s_flag);

//		ft_str_treatment.c
void	ft_putchar(char c, t_flag * s_flag);
void	ft_putstr(char *s, t_flag * s_flag);
void	ft_putstrlen(char *s, int len, t_flag * s_flag);
void	ft_printf_str(char *src, int len, t_flag * s_flag);



//		ft_nbr_treatment.c
void	ft_printf_nbr(char * src, t_flag * s_flag);

//		ft_libft.c
int		ft_isneg(int num, t_flag * s_flag);
int		ft_strindex(char *tab, char element);
char	*ft_convert_base(int base_len, long int nbr, char *base, char * result);


//		ft_parser.c
int     ft_printf(const char *src, ...);
#endif
