/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:55:25 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/22 04:10:39 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_flag_x_xl(va_list args, t_flags *flag,
									t_counter *count, int ch)
{
	char	*str;
	int		j;

	j = 0;
	str = ft_itoa_hex(va_arg(args, unsigned int));
	if (!(*str == '0' && flag->precision == 0))
	{
		if (ch)
			while (str[j] != '\0' && ++j)
				str[j - 1] = ft_toupper(str[j - 1]);
		if (flag->precision < (int)ft_strlen(str))
			flag->precision = ft_strlen(str);
		if (flag->width < flag->precision)
			flag->width = flag->precision;
		if (flag->dash == 0)
			print_padding(flag, count, flag->width - flag->precision);
		print_zero(count, flag->precision - ft_strlen(str));
		ft_putstr(count, str, ft_strlen(str));
		if (flag->dash == 1)
			print_padding(flag, count, flag->width - flag->precision);
	}
	else
		print_padding(flag, count, flag->width - flag->precision);
	free(str);
	count->i = count->j + 1;
}

void		print_flag_p_a(t_flags *flag, t_counter *count, char *str)
{
	if (flag->dash == 0)
	{
		if (flag->zero == 1)
			ft_putstr(count, "0x", 2);
		print_padding(flag, count, flag->width - flag->precision - 2);
	}
	if (flag->zero == 0)
		ft_putstr(count, "0x", 2);
	print_zero(count, flag->precision - ft_strlen(str));
	ft_putstr(count, str, ft_strlen(str));
	if (flag->dash == 1)
		print_padding(flag, count, flag->width - flag->precision - 2);
}

void		print_flag_p(va_list args, t_flags *flag, t_counter *count)
{
	char *str;

	str = ft_itoa_hex(va_arg(args, unsigned long int));
	if (!(*str == '0' && flag->precision == 0))
	{
		if (flag->precision < (int)ft_strlen(str))
			flag->precision = ft_strlen(str);
		if (flag->width < flag->precision + 2)
			flag->width = flag->precision + 2;
		print_flag_p_a(flag, count, str);
	}
	else
	{
		if (flag->width < 2)
			flag->width = 2;
		if (flag->dash == 0)
			print_padding(flag, count, flag->width - 2);
		ft_putstr(count, "0x", 2);
		if (flag->dash == 1)
			print_padding(flag, count, flag->width - 2);
	}
	free(str);
	count->i = count->j + 1;
}
