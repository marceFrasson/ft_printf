/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_c_s_d_i_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:32:46 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/20 18:10:27 by mfrasson         ###   ########.fr       */
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

void		ft_putstr_size(t_flags *flag, t_counter *count, char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (flag->size--)
		{
			write(1, &str[i], 1);
			i++;
			count->len++;
		}
	}
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
		char *str;

	str = va_arg(args, char *);
	flag->padding = ' ';
	flag->size = ft_strlen(str);
	if (str == NULL)
		str = "(null)";
	if (flag->dot == 1)
	{
		if (flag->size < flag->precision)
		{
			if (flag->dash == 0)
				print_padding(flag, count);
			ft_putstr(count, str);
			if (flag->dash == 1)
				print_padding(flag, count);
		}
		else
		{
			flag->size = flag->precision - 2;
			if (flag->dash == 0)
				print_padding(flag, count);
			ft_putstr_size(flag, count, str);
			flag->size = flag->precision;
			if (flag->dash == 1)
				print_padding(flag, count);
		}
	}
	else
	{
		if (flag->dash == 0)
			print_padding(flag, count);
		ft_putstr_size(flag, count, str);
		flag->size = flag->precision;
		if (flag->dash == 1)
			print_padding(flag, count);
	}
}

void		print_flag_d_i_u(va_list args, t_flags *flag, t_counter *count)
{
	int ch;

	ch = va_arg(args, int);
	if (flag->zero == 1)
		flag->padding = '0';
	else
		flag->padding = ' ';
	flag->size = int_len(ch);
	if (flag->dash == 0)
	{
		if (flag->dot == 1)
		{
			flag->padding = ' ';
			if (flag->precision > flag->size)
				while (flag->width-- > flag->precision)
					ft_putchar(count, flag->padding);
			else
				while (flag->width-- > flag->size)
					ft_putchar(count, flag->padding);
			flag->padding = '0';
			print_padding_precision(flag, count);
			ft_putnbr(count, ch);
		}
		else
		{
			print_padding(flag, count);
			ft_putnbr(count, ch);
		}
	}
	if (flag->dash == 1)
	{
		if (flag->dot == 1)
		{
			flag->padding = '0';
			print_padding_precision(flag, count);
			ft_putnbr(count, ch);
			flag->padding = ' ';
			if (flag->width > flag->precision)
			{
				flag->padding = ' ';
				if (flag->size == flag->precision + flag->difference)
					while (flag->width-- > flag->precision)
						ft_putchar(count, flag->padding);
				if (flag->size > flag->precision + flag->difference)
					while (--flag->width + 1 > flag->size)
						ft_putchar(count, flag->padding);
				if (flag->size < flag->precision + flag->difference)
					while (--flag->width + 1 > flag->precision + flag->difference)
						ft_putchar(count, flag->padding);
			}
		}
		else
		{
			ft_putnbr(count, ch);
			print_padding(flag, count);
		}
	}
}
