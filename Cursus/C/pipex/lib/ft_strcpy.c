/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:34:51 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:08:56 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* ENGLISH: Copies a string from source to destination.
 *
 * SPANISH: Copia una cadena desde el origen al destino.
 * 
 * @param {const char *} s
 * 	- The string to copy from. / La cadena de la que copiar.
 * @param {char *} dest
 * 	- The destination buffer where the string will be copied. / El búfer de
 * destino donde se copiará la cadena. 
 * @return {char *}
 *  - Pointer to the destination string. / Puntero a la cadena de destino.
 */
char	*ft_strcpy(char *dest, const char *src)
{
	char	*d;

	d = dest;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dest);
}
