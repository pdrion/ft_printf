/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: philippe <philippe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 19:24:24 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/12 00:21:27 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = 0;
	if (n < 0)
		ft_putchar('-');
	nb = (n < 0 ? -n : n);
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int		ft_isascii(char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char hex_digit(int v)
{
    if (v >= 0 && v < 10)
        return '0' + v;
    else
        return 'a' + v - 10; // <-- Here	
}
void ft_putspaces(int space)
{
	while(space > 1)
		{
			ft_putchar(' ');
			space = space -1;
		}
}
int		ft_atoi(const char *str)
{
	int i;
	int nb;
	int isneg;

	i = 0;
	nb = 0;
	isneg = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		isneg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - 48);
	return (isneg * nb);
}
