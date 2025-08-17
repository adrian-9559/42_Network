/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:17:07 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:57:50 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* ENGLISH: Searches for the first occurrence of a character in a string.
 *
 * SPANISH: Busca la primera ocurrencia de un carácter en una cadena.
 * 
 * @param {const char *} s
 * 	- The string to search in. / La cadena en la que buscar.
 * @param {int} c
 * 	- The character to find (as an int). / El carácter a encontrar (como un int).
 * @return {char *}
 * 
 * 	- Pointer to the first occurrence of the character, or NULL if not found.
 * 
 * 	- Puntero a la primera ocurrencia del carácter, o NULL si no se encuentra.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
