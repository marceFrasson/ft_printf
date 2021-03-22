/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:52:21 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 23:34:51 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(t_counter *count, char c)
{
	write(1, &c, 1);
	count->len++;
}


void		print_padding(t_flags *flag, t_counter *count, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar(count, flag->padding);
		i++;
	}
}

int			ft_putnbr(t_counter *count, int n)
{
	unsigned	i;
	int			j;

	j = 1;
	if (n < 0)
	{
		i = n * -1;
		j++;
	}
	else
		i = n;
	if (i >= 10)
		j += ft_putnbr(count, i / 10);
	ft_putchar(count, (i % 10 + 48));
	return (j);
}

int			ft_putnbr_unsg(t_counter *count, int n)
{
	unsigned	i;
	unsigned	j;

	j = 1;
	if (n < 0)
	{
		i = n * -1;
		j++;
	}
	else
		i = n;
	if (i >= 10)
		j += ft_putnbr(count, i / 10);
	ft_putchar(count, (i % 10 + 48));
	return (j);
}

void		ft_putstr(t_counter *count, char *str, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
        ft_putchar(count, str[i - 1]);
}
