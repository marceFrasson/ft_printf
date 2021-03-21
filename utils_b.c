/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:11:56 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 10:47:37 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnbr(t_counter *count, int n)
{
	unsigned	i;
	int			j;

	j = 1;
	if (n < 0)
	{
		ft_putchar(count, '-');
		i = n * -1;
		j++;
	}
	else
		i = n;
	if (i >= 10)
	{
		j += ft_putnbr(count, i / 10);
	}
	ft_putchar(count, (i % 10 + 48));
	count->len++;
	return (j);
}

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char		*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
