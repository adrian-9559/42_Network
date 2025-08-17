/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:50:25 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:57:14 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Counts the number of words in a string separated 
 *		by a specific character.
 *
 * SPANISH: Cuenta el número de palabras en una cadena separadas 
 * 		por un carácter específico.
 *
 * @param {const char *} s
 *      - The string to analyze.
 *      - La cadena a analizar.
 * @param {char} c
 *      - The character used to separate words.
 *      - El carácter utilizado para separar palabras.
 *
 * @returns {size_t}
 *      - Returns the number of words found in the string.
 *      - Retorna el número de palabras encontradas en la cadena.
 */
size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}
