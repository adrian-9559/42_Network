/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:06:03 by adriescr          #+#    #+#             */
/*   Updated: 2025/11/09 16:09:19 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Checks if the given string represents a positive integer.
 *
 * SPANISH: Comprueba si la cadena dada representa un entero positivo.
 *
 * @param str The string to check. / La cadena a comprobar.
 * @return 1 if the string is a positive integer, 0 otherwise. /
 * 	   1 si la cadena es un entero positivo, 0 en caso contrario.
 */
int ft_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
