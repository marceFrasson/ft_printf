/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:46:34 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 22:16:53 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			int_len(int num)
{
	int i;

	i = 1;
	if (num < 0)
		i++;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void		init_flag(t_flags *flag)
{
	flag->padding = ' ';
	flag->precision = -1;
	flag->width = 0;
	flag->dash = 0;
	flag->zero = 0;
	flag->read_number = 0;
	flag->read_star = 0;
}

int			unsgn_int_len(unsigned int num)
{
	unsigned int i;

	i = 1;
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void		print_zero(t_counter *count, int len)
{
	while (len--)
	{
		write(1, "0", 1);
		count->len++;
	}
}
