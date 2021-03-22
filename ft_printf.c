/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 22:49:35 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 22:10:02 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		which_flag(va_list args, t_flags *flag,
							t_counter *count, const char *input)
{
	if (input[count->i] == 'c')
        print_flag_c(flag, count, (va_arg(args, int)));
    else if (input[count->i] == 's')
        print_flag_s(args, flag, count);
    else if (input[count->i] == 'd' || input[count->i] == 'i')
        print_flag_d_i(args, flag, count);
    else if (input[count->i] == 'u')
        print_flag_u(args, flag, count);
    else if (input[count->i] == 'x')
        print_flag_x_X(args, flag, count, 0);
    else if (input[count->i] == 'X')
        print_flag_x_X(args, flag, count, 1);
    else if (input[count->i] == 'p')
        print_flag_p(args, flag, count);
    else if (input[count->i] == '%')
         print_flag_c(flag, count, '%');
    else
       ft_putchar(count, '%');
}

void		which_format(va_list args, t_counter *count, const char *input)
{	
	t_flags flag;
	
	init_flag(&flag);
	while (input[count->i] == '0' || input[count->i] == '-')
	{
		if (input[count->i] == '0' && flag.dash == 0)
		{
			flag.padding = '0';
			flag.zero = 1;
		}
		if (input[count->i] == '-')
		{
			flag.dash = 1;
			flag.zero = 0;
			flag.padding = ' ';
		}
		count->i++;
	}
	if (input[count->i] == '*')
		is_it_star(args, &flag, count, input);
	else if (read_number(&flag, count, input) == 1)
		flag.width = flag.read_number;
	if (input[count->i] == '.')
	{
		count->i++;
		if (input[count->i] == '*')
			is_it_star(args, &flag, count, input);
		else if (read_number(&flag, count, input) == 1)
		{
			flag.precision = flag.read_number;
			if (count->i + 1 != '%')
			{
				flag.zero = 0;
				flag.padding = ' ';
			}
		}
	}
	which_flag(args, &flag, count, input);
	count->i++;
}

int			ft_printf(const char *input, ...)
{
	va_list args;
	t_counter count;

	va_start(args, input);
	count.i = 0;
	count.len = 0;
	while (input[count.i] != '\0')
	{
		if (input[count.i] == '%')
		{
			count.i++;
			which_format(args, &count, input);
		}
		else
		 	ft_putchar(&count, input[count.i++]);
	}
	va_end(args);
	return (count.len);
}
