/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:47:57 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:00:18 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Copies memory from one location to another.
 *
 * SPANISH: Copia memoria de una ubicación a otra.
 *
 * @param dst   The destination memory location. /
 *              La ubicación de memoria de destino.
 *
 * @param src   The source memory location. /
 *              La ubicación de memoria de origen.
 *
 * @param n    The number of bytes to copy. /
 *             El número de bytes a copiar.
 *
 * @returns A pointer to the destination memory location. /
 *          Un puntero a la ubicación de memoria de destino.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
