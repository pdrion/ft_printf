/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:17:33 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/19 21:02:54 by pdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

int main(int argc, char **argv)
{
	char t;
	int i = 20;
	void *p;

	int retvalue;
	retvalue = 0;
	p = &i;
		
	if (argc > 1)
		{
			t = *argv[1];
			printf("la variable t est %c\n", t);
			
			}
	//ft_printf("imperssion de c : %5c\npuis de s : %#45.80s\npuis d'un nombre d : %d\npuis d'un nombre i : %i\npuis d'un nombre u : %u\net enfin d'une adresse p : %p\n\n", 'P', "blabla", 42, -123, -123, p);

	
	retvalue = ft_printf("%.*s\n", 7, "hello");
	printf("%d\n",retvalue );
	retvalue = printf("%.*s\n", 7, "hello");
	printf("%d\n",retvalue );
	//printf("%.*s\n", 7, "hello");
	//printf("%0-10.5d\n", -216);
	//ft_printf("%0-10.5d\n\n", -216);
	//	printf("%-10.5d\n", -216);
	ft_printf("%0-8.5d", 34);
	printf("%0-8.5d", 34);

	return (0);

}
