/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:49:35 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/17 17:41:40 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *input, ...)
{
	va_list args;
	t_counter count;

	va_start(args, input);
	count.i = 0;
	count.len = 0;
	while (input[count.i] != '\0')
	{
		if (input[count.i] == '%')
		{
			count.i++;
			which_format(args, &count, input);
		}
		else
		 	ft_putchar(&count, input[count.i++]);
	}
	va_end(args);
	return (count.len);
}
