/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_c_s_d_i_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:32:46 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 10:29:47 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(t_flags *flag, t_counter *count)
{
	while (flag->width > flag->size && flag->size >= 0)
	{
		ft_putchar(count, flag->padding);
		flag->width--;
	}
	flag->width = 0;
}

void		print_putstr(t_flags *flag, t_counter *count, char *str)
{
	if (flag->dash == 0)
		print_padding(flag, count);
	ft_putstr(count, str);
	if (flag->dash == 1)
		print_padding(flag, count);
}

void		print_flag_c(va_list args, t_flags *flag, t_counter *count)
{
	int ch;

	ch = va_arg(args, int);
	if (flag->zero == 1)
		flag->padding = '0';
	else
		flag->padding = ' ';
	flag->size = 1;
	if (flag->dash == 0)
		print_padding(flag, count);
	ft_putchar(count, ch);
	if (flag->dash == 1)
		print_padding(flag, count);
}

void		print_flag_s(va_list args, t_flags *flag, t_counter *count)
{
	char	*str;
	int		temp;
	
	flag->precision -= 2;
	str = va_arg(args, char *);
	if (flag->zero == 1)
		flag->padding = '0';
	else
		flag->padding = ' ';
	flag->size = ft_strlen(str);
	if (flag->zero_size == 1)
	{
		flag->size = 0;
		flag->precision = 0;
	}
	if (str == NULL)
		str = "(null)";
	if (flag->dot == 1)
	{
		if (flag->size < flag->precision)
			print_putstr(flag, count, str);
		else
		{
			flag->size = flag->precision;
			print_putstr_size(flag, count, str);
		}
	}
	else
	{
		if (flag->dash == 0)
			print_padding(flag, count);
		temp = flag->size;
		ft_putstr_size(flag, count, str);
		flag->size = temp;
		if (flag->dash == 1)
			print_padding(flag, count);
	}
}

void		print_flag_d_i_u(va_list args, t_flags *flag, t_counter *count)
{
	int ch;
	int temp;

	ch = va_arg(args, int);
	if (flag->zero == 1)
		flag->padding = '0';
	else
		flag->padding = ' ';
	flag->size = int_len(ch);
	flag->precision -= 2;
	if (flag->zero_size == 1)
	{
		flag->size = 0;
		flag->precision = 0;
	}
	if (ch < 0)
		ft_putchar(count, '-');
	if (flag->dot == 0)
	{
		if (flag->dash == 0)
			print_padding(flag, count);
		ft_putnbr_unsg(count, ch);
		if (flag->dash == 1)
			print_padding(flag, count);
	}
	else
	{
		if (flag->dash == 0)
		{
			print_padding_width(flag, count);
			flag->padding = '0';
			print_padding_precision(flag, count);
			if (flag->precision != 0)
				ft_putnbr_unsg(count, ch);
		}
		if (flag->dash == 1)
		{
			flag->padding = '0';
			temp = flag->precision;
			print_padding_precision(flag, count);
			flag->precision = temp;
			if (flag->precision != 0)
				ft_putnbr_unsg(count, ch);
			if (flag->zero == 0)
				flag->padding = ' ';
			while (flag->width-- > flag->precision)
				ft_putchar(count, flag->padding);
		}
	}
}
