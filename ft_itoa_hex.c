/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:54:12 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/22 11:52:40 by mfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_hconvert(unsigned long int nbr, char *base)
{
    char                    *converted;
    int                        base_len;
    unsigned long int        i;
    int                        size;

    base_len = ft_strlen(base);
    i = nbr;
    size = 1;
    while (i /= base_len)
        size++;
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

/* static void	invert_hex(t_itoa_hex *aux)
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
	ft_putstr(count, "-----", 5);
	ft_putnbr(count, aux.length);
	ft_putstr(count, "-----", 5);
	if (!(aux.hex = (char *)malloc((aux.length + 6) * sizeof(char))))
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
	invert_hex(&aux);
	return (aux.hex);
} */
