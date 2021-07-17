/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marce <marce@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:55:25 by mfrasson          #+#    #+#             */
/*   Updated: 2021/07/17 20:04:13 by marce            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	loop(unsigned long int i, int base_len, int size)
{
	while (i)
	{
		i /= base_len;
		size++;
	}
	size--;
	return (size);
}

char	*ft_hconvert(unsigned long int nbr, char *base)
{
	char				*converted;
	int					base_len;
	unsigned long int	i;
	int					size;

	base_len = ft_strlen(base);
	i = nbr;
	size = 1;
	size = loop(i, base_len, size);
	converted = (char *)malloc(size + 1);
	if (converted == NULL)
		return (NULL);
	converted[size--] = '\0';
	if (nbr == 0)
		converted[size] = '0';
	while (nbr > 0)
	{
		converted[size--] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (converted);
}

void	print_flag_x_xl(va_list args, t_flags *flag,
	t_counter *count, int ch)
{
	char	*str;
	int		j;

	j = 0;
	str = ft_hconvert(va_arg(args, unsigned int), HEX_LOWER);
	if (!(*str == '0' && flag->precision == 0))
	{
		if (ch)
			while (str[j] != '\0' && ++j)
				str[j - 1] = ft_toupper(str[j - 1]);
		if (flag->precision < (int)ft_strlen(str))
			flag->precision = ft_strlen(str);
		if (flag->width < flag->precision)
			flag->width = flag->precision;
		if (flag->dash == 0)
			print_padding(flag, count, flag->width - flag->precision);
		print_zero(count, flag->precision - ft_strlen(str));
		ft_putstr(count, str, ft_strlen(str));
		if (flag->dash == 1)
			print_padding(flag, count, flag->width - flag->precision);
	}
	else
		print_padding(flag, count, flag->width - flag->precision);
	free(str);
	count->i = count->j + 1;
}

static void	print_flag_p_a(t_flags *flag, t_counter *count, char *str)
{
	if (flag->dash == 0)
	{
		if (flag->zero == 1)
			ft_putstr(count, "0x", 2);
		print_padding(flag, count, flag->width - flag->precision - 2);
	}
	if (flag->zero == 0)
		ft_putstr(count, "0x", 2);
	print_zero(count, flag->precision - ft_strlen(str));
	ft_putstr(count, str, ft_strlen(str));
	if (flag->dash == 1)
		print_padding(flag, count, flag->width - flag->precision - 2);
}

void	print_flag_p(va_list args, t_flags *flag, t_counter *count)
{
	char	*str;

	str = ft_hconvert(va_arg(args, unsigned long int), HEX_LOWER);
	if (!(*str == '0' && flag->precision == 0))
	{
		if (flag->precision < (int)ft_strlen(str))
			flag->precision = ft_strlen(str);
		if (flag->width < flag->precision + 2)
			flag->width = flag->precision + 2;
		print_flag_p_a(flag, count, str);
	}
	else
	{
		if (flag->width < 2)
			flag->width = 2;
		if (flag->dash == 0)
			print_padding(flag, count, flag->width - 2);
		ft_putstr(count, "0x", 2);
		if (flag->dash == 1)
			print_padding(flag, count, flag->width - 2);
	}
	free(str);
	count->i = count->j + 1;
}
