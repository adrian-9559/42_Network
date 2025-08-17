/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:19:40 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:10:25 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* ENGLISH: Calculates the length of a string (excluding the null terminator).
 *
 * SPANISH: Calcula la longitud de una cadena (excluyendo el terminador nulo).
 * 
 * @param {const char *} s
 * 	- The string whose length is to be determined. / 
 * 	La cadena cuya longitud se va a determinar.
 * @return {size_t}
 * 	- The number of characters in the string. /
 * 	El número de caracteres en la cadena.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}
