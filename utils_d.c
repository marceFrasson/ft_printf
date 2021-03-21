/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 19:10:33 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/21 15:51:12 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr_up(t_counter *count, char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			write(1, &str[i], 1);
			i++;
			count->len++;
		}
	}
}

static void	invert_hex(t_itoa_hex *aux)
{
	int i;

	i = 0;
	while (i < (aux->length / 2))
	{
		aux->temp = aux->hex[i];
		aux->hex[i] = aux->hex[aux->length - i - 1];
		aux->hex[aux->length - i - 1] = aux->temp;
		i++;
	}
}

static void	convert_to_hex(t_itoa_hex *aux, unsigned long int *number)
{
	while (*number > 0)
	{
		aux->to_hex = *number % 16;
		if (aux->to_hex < 10)
			aux->hex[aux->length] = aux->to_hex + 48;
		else
			aux->hex[aux->length] = aux->to_hex + aux->case_c;
		*number /= 16;
		aux->length++;
	}
}

char		*ft_itoa_hex(t_counter *count, unsigned long int number)
{
	t_itoa_hex	aux;

	aux.length = int_len(number);
	if (!(aux.hex = (char *)malloc((aux.length + 1) * sizeof(char))))
		return (NULL);
	aux.case_c = 87;
	if (number == 0)
	{
		aux.hex[0] = '0';
		aux.hex[1] = '\0';
		return (aux.hex);
	}
	aux.length = 0;
	convert_to_hex(&aux, &number);
	aux.hex[aux.length] = '\0';
	aux.length = ft_strlen(aux.hex);
	//count->len += aux.length;
	invert_hex(&aux);
	return (aux.hex);
}

void		init_flag(t_flags *flag)
{
	flag->justify = 0;
	flag->padding = 0;
	flag->precision = 0;
	flag->width = 0;
	flag->dash = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->star = 0;
	flag->read_number = 0;
	flag->read_star = 0;
	flag->size = 0;
	flag->ch = 0;
	flag->str = NULL;
	flag->read_number_precision = 0;
	flag->is_digit = 0;
	flag->is_alpha = 0;
	flag->is_hexa = 0;
	flag->is_prcnt = 0;
	flag->read = 0;
}
