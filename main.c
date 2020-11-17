/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:17:33 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/15 18:38:39 by pdrion           ###   ########.fr       */
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
	//ft_printf("imperssion de c : %5c\npuis de s : %#45.80s\npuis d'un nombre d : %d\npuis d'un nombre i : %i\npuis d'un nombre u : %u\net enfin d'une adresse p : %p\n\n", 'P', "blabla", 42, -123, -123, p);

	
	ft_printf("%.*s\n", 7, "hello");
	printf("%.*s\n", 7, "hello");
	printf("%0-10.5d\n", -216);
	ft_printf("%0-10.5d\n", -216);	
	//ft_printf("%-5c, %4c\n",'a', 'B');
	//printf("%-5c, %4c\n",'a', 'B');
	//printf("test de i %i\n", -123);
	//printf("test de u %u\n", 123);
	//printf("test de u %u\n", -123);
	//printf("test de p %p\n", p);
	//ft_printf("%-5s, %40s\n","blabla", "blublu");
	//printf("%-5s, %4s\n","blabla", "blublu");
	return (0);

}
