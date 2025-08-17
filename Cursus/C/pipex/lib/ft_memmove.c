/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:33:26 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:56:57 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Copies memory from source to destination, handling 
 *		overlapping regions.
 *
 * SPANISH: Copia memoria desde el origen al destino, manejando 
 * 		regiones superpuestas.
 *
 * @param dst
 *      The destination memory area. / El área de memoria de destino.
 * @param src
 *      The source memory area. / El área de memoria de origen.
 * @param len
 *      The number of bytes to copy. / El número de bytes a copiar.
 *
 * @return {void*}
 *      Returns the destination pointer. / Devuelve el puntero de destino.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else if (d > s)
	{
		d += len;
		s += len;
		while (len--)
			*(--d) = *(--s);
	}
	return (dst);
}
