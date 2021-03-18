/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:03:20 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/18 14:38:56 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *str = "was";
	char *ch = "as";
	
	ft_printf("\n   pntr |%020p|   string |%10s|   char |%-10c|   prcnt |%%|   digit |%-015d|\n\n", &*ch, str, 'w', 465782);
	
	printf("   pntr |%020p|   string |%10s|   char |%-10c|   prcnt |%%|   digit |%-015d|\n\n", &*ch, str, 'w', 465782);
	return (0);
	//printf("   my %s and %p\n", ft_itoa_hex(&*str), &*str);
}
