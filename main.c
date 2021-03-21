/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:03:20 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 08:05:19 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *str = "ADFJK";
	int ch;
	
	ft_printf("\n   pntr |%-20.25p|   string |%15s|   char |%-20.4c|   prcnt |%5%|   digit |%15d|\n\n", &*str, str, 'w', 465782);
	
	ch = printf("   pntr |%-20.25p|   string |%15s|   char |%-20.4c|   prcnt |%5%|   digit |%15d|\n\n", &*str, str, 'w', 465782);



	ft_printf("\n   pntr |%020.25p|   string |%-15s|   char |%20.4c|   prcnt |%-5%|   digit |%015.15d|\n\n", &*str, str, 'w', 465782);
	
	ch = printf("   pntr |%020.25p|   string |%-15s|   char |%20.4c|   prcnt |%-5%|   digit |%015.15d|\n\n", &*str, str, 'w', 465782);


	ft_printf("\n   pntr |%20.5p|   string |%025s|   char |%-4.10c|   prcnt |%-5.2%|   digit |%-15.10d|\n\n", &*str, str, 'w', 465782);
	
	ch = printf("   pntr |%20.5p|   string |%025s|   char |%-4.10c|   prcnt |%-5.2%|   digit |%-15.10d|\n\n", &*str, str, 'w', 465782);



	ft_printf("\n   pntr |%-5.20p|   string |%-5.15s|   char |%4.10c|   prcnt |%5.%|   digit |%015d|\n\n", &*str, str, 'w', 465782);
	
	ch = printf("   pntr |%-5.20p|   string |%-5.15s|   char |%4.10c|   prcnt |%5.%|   digit |%015d|\n\n", &*str, str, 'w', 465782);

	ft_printf("\n   pntr |%05.25p|   string |%20.5s|   char |%020.4c|   prcnt |%0%|   digit |%010.15d|\n\n", &*str, str, 'w', 465782);
	
	ch = printf("   pntr |%05.25p|   string |%20.5s|   char |%020.4c|   prcnt |%0%|   digit |%010.15d|\n\n", &*str, str, 'w', 465782);
	return (0);
}
