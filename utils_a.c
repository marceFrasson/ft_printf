/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:52:57 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/19 13:16:11 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		ft_putchar(t_counter *count, char c)
{
	write(1, &c, 1);
	count->len++;
}

void		put_space(t_flags *flag, t_counter *count)
{
	while (flag->size-- > 0)
		ft_putchar(count, ' ');
}

void		ft_putstr(t_counter *count, char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
			count->len++;
		}
	}
}
