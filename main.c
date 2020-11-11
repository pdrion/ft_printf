/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:17:33 by pdrion            #+#    #+#             */
/*   Updated: 2020/11/11 21:30:41 by pdrion           ###   ########.fr       */
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
	ft_printf("la c'est mon premier string char : %c\n string %s\n nombre d : %d\n nombre i : %i\n nombre u : %u\n adressse de p : %p\n\n", 'P', "blabla", 42, -123, -123, p);
	printf("test de i %i\n", -123);
	printf("test de u %u\n", 123);
	printf("test de u %u\n", -123);
	printf("test de p %p\n", p);
	return (0);

}
