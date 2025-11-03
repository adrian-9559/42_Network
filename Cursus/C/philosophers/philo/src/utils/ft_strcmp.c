/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:01:44 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/30 13:03:19 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philosophers.h"

/**
 * ENGLISH: Compares two strings.
 *
 * SPANISH: Compara dos cadenas.
 *
 * @param s1   The first string. /
 *              La primera cadena.
 * @param s2   The second string. /
 *              La segunda cadena.
 *
 * @returns 0 if equal, negative if s1 < s2, positive if s1 > s2. /
 *          0 si son iguales, negativo si s1 < s2, positivo si s1 > s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
