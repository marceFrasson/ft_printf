/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrasson <mfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:48:58 by mfrasson          #+#    #+#             */
/*   Updated: 2021/03/20 12:04:36 by mfrasson         ###   ########.fr       */
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
