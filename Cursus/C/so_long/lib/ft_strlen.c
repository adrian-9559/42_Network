/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:39:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:02:06 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Calculates the length of a string.
 *
 * SPANISH: Calcula la longitud de una cadena.
 *
 * @param s   The string to measure. /
 *            La cadena a medir.
 *
 * @returns The length of the string. /
 *          La longitud de la cadena.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
