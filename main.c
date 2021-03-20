/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:03:20 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/20 19:31:38 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *str = "ADFJK";
	int ch;
	
	ft_printf("\n   pntr |%-20.25p|   string |%5s|   char |%-20.4c|   prcnt |%020.%|   digit |%15d|\n\n", NULL, str, 'w', 465782);
	
	ch = printf("   pntr |%-20.25p|   string |%s|   char |%-20.4c|   prcnt |%020.%|   digit |%15d|\n\n", &*str, str, 'w', 465782);
	printf("\n\t %d\n\n", ch);
	return (0);
}
