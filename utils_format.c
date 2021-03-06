/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marce <marce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:58:09 by mfrasson          #+#    #+#             */
/*   Updated: 2021/07/17 20:07:59 by marce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_number(t_flags *flag, t_counter *count, const char *input)
{
	flag->read_number = 0;
	if (ft_isdigit((int)input[count->j]))
	{
		while (ft_isdigit((int)input[count->j]))
		{
			flag->read_number = (flag->read_number * 10)
				+ (int)input[count->j] - '0';
			count->j++;
		}
		return (1);
	}
	else
		return (0);
}

static void	is_it_star_a(t_flags *flag)
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

void	is_it_star(va_list args, t_flags *flag,
	t_counter *count, const char *input)
{
	flag->read_star = 0;
	flag->read_star = va_arg(args, int);
	if (input[count->j - 1] == '.')
	{
		if (flag->read_star >= 0)
		{
			flag->precision = flag->read_star;
			if (input[count->j] != '%')
			{
				flag->zero = 0;
				flag->padding = ' ';
			}
		}
	}
	else
		is_it_star_a(flag);
	count->j++;
}
