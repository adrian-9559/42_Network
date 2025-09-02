/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:53:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:00:08 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Checks if a string represents a valid number.
 *
 * SPANISH: Verifica si una cadena representa un número válido.
 *
 * @param str   The string to check. /
 *              La cadena a verificar.
 *
 * @returns 1 if the string is a valid number, 0 otherwise. /
 *          1 si la cadena es un número válido, 0 en caso contrario.
 */
int	ft_is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_is_digit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}
