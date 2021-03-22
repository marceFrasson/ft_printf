/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:58:09 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/22 02:00:31 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_number(t_flags *flag, t_counter *count, const char *input)
{
	flag->read_number = 0;
	if (ft_isdigit((int)input[count->i]))
	{
		while (ft_isdigit((int)input[count->i]))
		{
			flag->read_number = (flag->read_number * 10)
										+ (int)input[count->i] - '0';
			count->i++;
		}
		return (1);
	}
	else
		return (0);
}

void		is_it_star(va_list args, t_flags *flag, t_counter *count, const char *input)
{
	flag->read_star = 0;
	flag->read_star = va_arg(args, int);
	if (input[count->i - 1] == '.' )
	{
		if (flag->read_star >= 0)
		{
			flag->precision = flag->read_star;
			if (count->i + 1 != '%')
			{
				flag->zero = 0;
				flag->padding = ' ';
			}
		}
	}
	else
	{
		if (flag->read_star < 0)
		{
			flag->width = flag->read_star * -1;
			flag->dash = 1;
			flag->zero = 0;
			flag->padding = ' ';
		}
		else
			flag->width = flag->read_star;
	}
	count->i++;
}
