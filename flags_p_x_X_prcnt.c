/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_p_x_X_prcnt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:09:56 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/18 14:42:27 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}

void		print_flag_p_x_X(va_list args, t_flags *flag, t_counter *count)
{
	char *str;

	str = ft_itoa_hex(va_arg(args, unsigned long int));
	if (flag->is_upper == 1)
		str = ft_strupcase(str);
	if (flag->zero == 1)
	{
		if (flag->is_pntr == 1)
			ft_putstr(count, "0x");
		flag->padding = '0';
	}
	else
		flag->padding = ' ';
	flag->size = ft_strlen(str);
	if (flag->is_pntr == 1)
		flag->size += 2;
	if (str == NULL)
		str = "(null)";
	if (flag->dash == 0)
		print_padding(flag, count);
	if (flag->is_pntr == 1 && flag->zero == 0)
		ft_putstr(count, "0x");
	ft_putstr(count, str);
	if (flag->dash == 1)
		print_padding(flag, count);
	free(str);
}

void		print_flag_prcnt(t_counter *count)
{
	char ch;

	ch = '%';
	ft_putchar(count, ch);
}
