/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:18:23 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:09:50 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/* ENGLISH: Duplicates a string by allocating memory and copying its contents.
 *
 * SPANISH: Duplica una cadena asignando memoria y copiando su contenido.
 * 
 * @param {const char *} s
 * 	- The string to duplicate. / La cadena a duplicar.
 * @return {char *}
 * 
 * 	- Pointer to the newly allocated duplicated string, or NULL if 
 * 	allocation fails.
 * 
 * 	- Puntero a la nueva cadena duplicada, o NULL si falla la asignación.
 */
char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	while (s1[len])
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
