/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:36:22 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:55:02 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Concatenates two strings.
 *
 * - Appends the source string to the destination string.
 * 
 * - Returns a pointer to the destination string.
 *
 * SPANISH: Concatena dos cadenas.
 *
 * - Anexa la cadena fuente a la cadena de destino.
 * 
 * - Devuelve un puntero a la cadena de destino.
 *
 * @param {char *} dest
 *      - The destination string. / 
 * 		La cadena de destino.
 * @param {const char *} src
 *      - The source string to append. / 
 * 		La cadena fuente a anexar.
 * @return {char *}
 *      - A pointer to the destination string. / 
 * 		Un puntero a la cadena de destino.
 */
char	*ft_strcat(char *dest, const char *src)
{
	char	*d;

	d = dest;
	while (*d)
		d++;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dest);
}
