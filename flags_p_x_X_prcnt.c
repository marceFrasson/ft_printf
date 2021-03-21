/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_p_x_X_prcnt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:09:56 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/20 20:49:11 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

void		print_padding_width(t_flags *flag, t_counter *count)
{
	while (flag->width > flag->precision)
	{
		ft_putchar(count, flag->padding);
		flag->width--;
	}
	flag->width = 0;
}

void		print_padding_width_plus(t_flags *flag, t_counter *count)
{
	while (flag->width + 2 > flag->precision)
	{
		ft_putchar(count, flag->padding);
		flag->width--;
	}
	flag->width = 0;
}

void		print_padding_precision(t_flags *flag, t_counter *count)
{
	while (flag->precision > flag->size)
	{
		ft_putchar(count, flag->padding);
		flag->precision--;
		flag->difference++;
	}
}

void	print_padding_plus(t_flags *flag, t_counter *count)
{
	while (flag->width + 2 > flag->size && flag->size >= 0)
	{
		ft_putchar(count, flag->padding);
		flag->width--;
	}
	flag->width = 0;
}

int			print_flag_p(va_list args, t_flags *flag, t_counter *count)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_itoa_hex(va_arg(args, unsigned long int));
	if (flag->is_upper == 1)
		str = ft_strupcase(str);
	if (flag->zero == 1 || flag->dot == 1)
		flag->padding = '0';
	else
		flag->padding = ' ';
	flag->size = ft_strlen(str);
	flag->size += 2;
	if (flag->dot == 1)
	{
		if (flag->precision < flag->size)
		{
			if (flag->dot == 1)
				flag->padding = ' ';
			if (flag->dash == 0)
				print_padding(flag, count);
			ft_putstr(count, "0x");
			if (str[i] != '0')
				ft_putstr(count, str);
			if (flag->dash == 1)
				print_padding(flag, count);
		}
		else
		{
			flag->padding = ' ';
			if (flag->precision > flag->width)
				ft_putstr(count, "0x");
			print_padding_width(flag, count);
			if (flag->precision < flag->width)
				ft_putstr(count, "0x");
			flag->padding = '0';
			print_padding_precision(flag, count);
			ft_putstr_size(flag, count, str);
		}
	}
	else
	{
		if (flag->dash == 1)
		{
			ft_putstr(count, "0x");
			ft_putstr(count, str);
			print_padding(flag, count);
		}
		else
		{
			ft_putstr(count, "0x");
			print_padding(flag, count);
			ft_putstr(count, str);
		}
	}
	return(1);
	free(str);
}

void		print_flag_x_X(va_list args, t_flags *flag, t_counter *count)
{
	char *str;

	str = ft_itoa_hex(va_arg(args, unsigned long int));
	str = ft_substr(str, 4, 8);
	if (flag->is_upper == 1)
		str = ft_strupcase(str);
	if (flag->zero == 1 || flag->dot == 1)
		flag->padding = '0';
	else
		flag->padding = ' ';
	flag->size = ft_strlen(str);
	if (flag->is_pntr == 1 || flag->dot == 1)
		flag->size += 2;
	if (str == NULL)
		str = "(null)";
	if (flag->dot == 1)
	{
		if (flag->precision < flag->size)
		{
			if (flag->dot == 1)
			flag->padding = ' ';
			if (flag->dash == 0)
				print_padding_plus(flag, count);
			ft_putstr(count, str);
			if (flag->dash == 1)
				print_padding(flag, count);
		}
		else
		{
			flag->padding = ' ';
			print_padding_width_plus(flag, count);
			flag->padding = '0';
			print_padding_precision(flag, count);
			ft_putstr_size(flag, count, str);
			flag->precision = flag->precision + flag->difference;
			if (flag->width > flag->precision)
			{
				flag->padding = ' ';
				print_padding_width(flag, count);
			}
		}
	}
	else
	{
		if (flag->dash == 1)
		{
			ft_putstr(count, str);
			print_padding(flag, count);
		}
		else
		{
			print_padding(flag, count);
			ft_putstr(count, str);
		}
	}
	free(str);
}

void		print_flag_prcnt(t_flags *flag, t_counter *count)
{
	char ch;

	ch = '%';
	flag->size = 1;
	if (flag->zero == 1)
		flag->padding = '0';
	else
		flag->padding = ' ';
	if (flag->dash == 0)
		print_padding(flag, count);
	ft_putchar(count, ch);
	if (flag->dash == 1)
		print_padding(flag, count);
}
