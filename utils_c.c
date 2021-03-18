/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:06:11 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/18 11:39:31 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strchr(const char *str, int c)
{
	char	*str1;
	int		i;

	str1 = (char *)str;
	i = 0;
	while (str1[i])
	{
		if (str1[i] == c)
		{
			return (&str1[i]);
		}
		i++;
	}
	if (!c)
	{
		return (&str1[i]);
	}
	return (0);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int			ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}

int			ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

void		ft_putstr_low(t_counter *count, char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = ft_tolower(str[i]);
			write(1, &str[i], 1);
			i++;
			count->len++;
		}
	}
}
