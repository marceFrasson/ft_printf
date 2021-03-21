/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_flag->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 23:06:48 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/12 13:55:03 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			read_number(t_flags *flag, t_counter *count, const char *input)
{
	if (input[count->i] == 0 && flag->read_number == 0)
	{
		return (0);
	}
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

void		which_alpha(va_list args, t_flags *flag,
								t_counter *count, const char *input)
{
	if (input[count->i] == 'c')
	{
		flag->is_alpha = 1;
		print_flag_c(args, flag, count);
	}
	if (input[count->i] == 's')
	{
		if (input[count->i - 1] == '.')
			flag->zero_size = 1;
		if (input[count->i - 1] == '0')
			flag->zero_size = 0;
		flag->is_alpha = 1;
		print_flag_s(args, flag, count);
	}
}

void		which_hexa(va_list args, t_flags *flag,
							t_counter *count, const char *input)
{
	if (input[count->i] == 'p' || input[count->i] == 'x'
										|| input[count->i] == 'X')
	{
		flag->is_hexa = 1;
		if (input[count->i] == 'p')
			print_flag_p(args, flag, count);
		else
		{
			if (input[count->i - 1] == '.')
				flag->zero_size = 1;
			if (input[count->i - 1] == '0')
				flag->zero_size = 0;
			if (input[count->i] == 'X')
				flag->is_upper = 1;
			print_flag_x_X(args, flag, count);
		}
	}
}

void		is_it_star(va_list args, t_flags *flag, t_counter *count, const char *input)
{
	if (input[count->i] == '*')
	{
		flag->read_star = va_arg(args, int);
		if (input[count->i - 1] == '.')
			if (flag->read_star >= 0)
				flag->precision = flag->read_star + 2;
		else
			flag->width = flag->read_star;
		if (flag->read_star < 0 && input[count->i - 1] != '.')
		{
			flag->dash = 1;
			flag->width = flag->read_star * -1;
		}
		flag->read_star = 0;
		count->i++;
		if (input[count->i] == '%')
		{
			if (flag->read == 0)
				ft_putchar(count, '%');
			else
				print_flag_prcnt(flag, count);
		}
	}
}

void		is_it_dot(t_flags *flag, t_counter *count, const char *input)
{
	if (input[count->i] == '.')
	{
		count->i++;
		flag->dot = 1;
		if (read_number(flag, count, input) == 1)
		{
			flag->precision = flag->read_number + 2;
			flag->read_number = 0;
			flag->read = 1;
		}
		if (input[count->i] == '%')
		{
			if (flag->read == 0)
				ft_putchar(count, '%');
			else
				print_flag_prcnt(flag, count);
		}
	}
}

void		which_flag(va_list args, t_flags *flag,
							t_counter *count, const char *input)
{
	which_alpha(args, flag, count, input);
	if (input[count->i] == 'd' ||
			input[count->i] == 'i' ||
				input[count->i] == 'u')
	{
		if (input[count->i - 1] == '.')
			flag->zero_size = 1;
		if (input[count->i - 1] == '0')
			flag->zero_size = 0;
		flag->is_digit = 1;
		print_flag_d_i_u(args, flag, count);
	}
	which_hexa(args, flag, count, input);
}

void		which_format(va_list args, t_counter *count, const char *input)
{	
	t_flags flag;
	
	init_flag(&flag);
	if (input[count->i] == '0')
	{
		count->i++;
		if (input[count->i] != '-' && input[count->i - 2] != '-')
		{
			flag.padding = '0';
			flag.zero = 1;
		}
		else
			flag.padding = ' ';
		read_number(&flag, count, input);
	}
	if (input[count->i] == '-')
	{
		count->i++;
		flag.dash = 1;
	}
	if (read_number(&flag, count, input) == 1)
	{
		flag.width = flag.read_number;
		flag.read = 1;
		flag.read_number = 0;
	}
	if (input[count->i] == '%')
	{
		if (flag.read == 0)
			ft_putchar(count, '%');
		else
			print_flag_prcnt(&flag, count);
	}
	is_it_dot(&flag, count, input);
	is_it_star(args, &flag, count, input);
	is_it_dot(&flag, count, input);
	is_it_star(args, &flag, count, input);
	which_flag(args, &flag, count, input);
	count->i++;
}
