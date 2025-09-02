/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:17:18 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:01:37 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Locates the first occurrence of a character in a string.
 *
 * SPANISH: Localiza la primera ocurrencia de un carácter en una cadena.
 *
 * @param s   The string to search. /
 *            La cadena a buscar.
 * @param c   The character to find. /
 *            El carácter a encontrar.
 *
 * @returns A pointer to the first occurrence of the character, or NULL if not found. /
 *          Un puntero a la primera ocurrencia del carácter, o NULL si no se encuentra.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
