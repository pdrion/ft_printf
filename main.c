/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:17:33 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/13 18:12:57 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int main(int argc, char **argv)
{
	char t;
	int i = 20;
	void *p;

	p = &i;
		
	if (argc > 1)
		{
			t = *argv[1];
			printf("la variable t est %c\n", t);
			
			}
	ft_printf("la %5c\n st %#s\n nomsefsf %d\n nomsdf %i\n nombre u : %u\n a de p : %p\n\n", 'P', "blabla", 42, -123, -123, p);
	ft_printf("%-5c, %4c\n",'a', 'B');
	printf("test de i %i\n", -123);
	printf("test de u %u\n", 123);
	printf("test de u %u\n", -123);
	printf("test de p %p\n", p);
	ft_printf("%-5s, %40s\n","blabla", "blublu");
	printf("%-5s, %4s\n","blabla", "blublu");
	return (0);

}
