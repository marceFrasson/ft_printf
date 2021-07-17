/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marce <marce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:54:49 by mfrasson          #+#    #+#             */
/*   Updated: 2021/07/17 20:04:57 by marce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_c(t_flags *flag, t_counter *count, int ch)
{
	if (flag->width < 1)
		flag->width = 1;
	if (flag->dash == 0)
		print_padding(flag, count, flag->width - 1);
	ft_putchar(count, ch);
	if (flag->dash == 1)
		print_padding(flag, count, flag->width - 1);
	count->i = count->j + 1;
}

void	print_flag_s(va_list args, t_flags *flag, t_counter *count)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if (flag->precision < 0 || flag->precision > (int)ft_strlen(str))
		flag->precision = (int)ft_strlen(str);
	if (flag->width < flag->precision)
		flag->width = flag->precision;
	if (flag->dash == 0)
		print_padding(flag, count, flag->width - flag->precision);
	ft_putstr(count, str, flag->precision);
	if (flag->dash == 1)
		print_padding(flag, count, flag->width - flag->precision);
	count->i = count->j + 1;
}
