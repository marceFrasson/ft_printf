/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:55:54 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/22 12:04:06 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_flag_d_i_a(t_flags *flag, t_counter *count, int ch)
{
	if (flag->dash == 0)
	{
		if (flag->zero == 1 && flag->is_negative == 1)
			ft_putchar(count, '-');
		print_padding(flag, count, flag->width - flag->precision);
	}
	if (flag->is_negative == 1)
		if (!(flag->dash == 0 && flag->zero == 1))
			ft_putchar(count, '-');
	print_zero(count, flag->precision - int_len(ch));
	ft_putnbr(count, ch);
	if (flag->dash == 1)
		print_padding(flag, count, flag->width - flag->precision);
}

void		print_flag_d_i(va_list args, t_flags *flag, t_counter *count)
{
	int ch;

	ch = va_arg(args, int);
	if (ch == INT_MIN)
		flag->width++;
	if (ch < 0)
	{
		ch *= -1;
		flag->is_negative = 1;
	}
	if (!(ch == 0 && flag->precision == 0))
	{
		if (flag->precision < int_len(ch))
			flag->precision = int_len(ch);
		if (flag->width < flag->precision)
			flag->width = flag->precision;
		if (flag->is_negative)
			flag->width -= 1;
		print_flag_d_i_a(flag, count, ch);
	}
	else
		print_padding(flag, count, flag->width - flag->precision);
	count->i = count->j + 1;
}

void		print_flag_u(va_list args, t_flags *flag, t_counter *count)
{
	unsigned int ch;

	ch = va_arg(args, unsigned int);
	if (!(ch == 0 && flag->precision == 0))
	{
		if (flag->precision < unsgn_int_len(ch))
			flag->precision = unsgn_int_len(ch);
		if (flag->width < flag->precision)
			flag->width = flag->precision;
		if (flag->dash == 0)
			print_padding(flag, count, flag->width - flag->precision);
		print_zero(count, flag->precision - unsgn_int_len(ch));
		ft_putnbr_unsg(count, ch);
		if (flag->dash == 1)
			print_padding(flag, count, flag->width - flag->precision);
	}
	else
	{
		print_padding(flag, count, flag->width - flag->precision);
	}
	count->i = count->j + 1;
}
