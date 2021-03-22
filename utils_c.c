/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 03:31:55 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/22 03:43:07 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_flag(t_flags *flag)
{
	flag->padding = ' ';
	flag->precision = -1;
	flag->is_negative = 0;
	flag->width = 0;
	flag->dash = 0;
	flag->zero = 0;
	flag->read_number = 0;
	flag->read_star = 0;
}

void		print_zero(t_counter *count, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, "0", 1);
		count->len++;
		i++;
	}
}
