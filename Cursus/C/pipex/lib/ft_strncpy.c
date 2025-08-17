/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:32:16 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:09:39 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* ENGLISH: Copies up to n characters from the source string to
 * the destination buffer.
 *
 * SPANISH: Copia hasta n caracteres de la cadena fuente al búfer de destino.
 * 
 * @param {char *} dest
 * 	- Destination buffer where the content is copied. /
 * 	Búfer de destino donde se copia el contenido.
 * @param {const char *} src
 * 	- Source string to copy from. / Cadena fuente desde la que copiar.
 * @param {size_t} n
 * 	- Maximum number of characters to copy. / Número máximo de 
 * 	caracteres a copiar.
 * @return {char *}
 * 
 * 	- Pointer to the destination buffer. / Puntero al búfer de destino.
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
