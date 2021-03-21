/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:48:58 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 11:59:02 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *str, unsigned int index, size_t size)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!(substr = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (!str || !substr)
		return (NULL);
	while ((i < size) && ((index + 1) < ft_strlen(str)) && (str[index + 1]))
	{
		substr[i] = str[index + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
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

void		print_putstr_size(t_flags *flag, t_counter *count, char *str)
{
	if (flag->dash == 0)
		print_padding(flag, count);
	ft_putstr_size(flag, count, str);
	flag->size = flag->precision;
	if (flag->dash == 1)
		print_padding(flag, count);
}

int			ft_putnbr_unsg(t_counter *count, int n)
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
	{
		j += ft_putnbr(count, i / 10);
	}
	ft_putchar(count, (i % 10 + 48));
	return (j);
}