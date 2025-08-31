/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:14:50 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:01:52 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Duplicates a string.
 *
 * SPANISH: Duplica una cadena.
 *
 * @param s   The string to duplicate. /
 *            La cadena a duplicar.
 *
 * @returns A pointer to the duplicated string, or NULL on failure. /
 *          Un puntero a la cadena duplicada, o NULL en caso de error.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
