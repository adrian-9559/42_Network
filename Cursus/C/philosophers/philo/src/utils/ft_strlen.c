/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:57:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/10/20 18:02:19 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Calculates the length of a null-terminated C string
 *          (number of characters before the terminating null byte).
 *
 * SPANISH: Calcula la longitud de una cadena C terminada en nulo
 *          (número de caracteres antes del byte nulo de terminación).
 *
 * @param s   The input string. /
 *            Cadena de entrada.
 *
 * @returns The number of characters in the string, excluding the
 *          terminating null byte. /
 *          Número de caracteres en la cadena, sin incluir el
 *          carácter nulo de terminación.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
