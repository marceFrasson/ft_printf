/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_c_s_d_i_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:32:46 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/18 14:42:21 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(t_flags *flag, t_counter *count)
{
	while (flag->size < flag->width && flag->size >= 1)
	{
		ft_putchar(count, flag->padding);
		flag->width--;
	}
	flag->width = 0;
}

void		print_flag_c(va_list args, t_flags *flag, t_counter *count)
{
	int ch;

	ch = (size_t)malloc(sizeof(int));
	ch = va_arg(args, int);
	flag->padding = ' ';
	flag->size = 1;
	flag->read_number_precision = 1;
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
	if (flag->dash == 0)
		print_padding(flag, count);
	ft_putstr(count, str);
	if (flag->dash == 1)
		print_padding(flag, count);
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
		print_padding(flag, count);
	ft_putnbr(count, ch);
	if (flag->dash == 1)
		print_padding(flag, count);
}
