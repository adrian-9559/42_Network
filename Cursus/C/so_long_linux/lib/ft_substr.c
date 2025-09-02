/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:15:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:02:16 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Extracts a substring from a string.
 *
 * SPANISH: Extrae una subcadena de una cadena.
 *
 * @param s       The original string. /
 *                La cadena original.
 * @param start   The starting index of the substring. /
 *                El índice de inicio de la subcadena.
 * @param len     The length of the substring. /
 *                La longitud de la subcadena.
 *
 * @returns A pointer to the new substring, or NULL on failure. /
 *          Un puntero a la nueva subcadena, o NULL en caso de error.
 */
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
