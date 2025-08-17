/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:14:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:55:06 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

/*
 * ENGLISH: Duplicates a word from a string.
 *
 * - Allocates memory for the new string.
 * - Returns NULL if memory allocation fails.
 *
 * SPANISH: Duplica una palabra de una cadena.
 *
 * - Asigna memoria para la nueva cadena.
 * - Devuelve NULL si falla la asignación de memoria.
 * 
 * @param {const char *} s
 *      - The string from which to duplicate the word. / 
 * 		La cadena de la que se va a duplicar la palabra.
 * @param {size_t} start
 *      - The starting index of the word in the string. / 
 * 		El índice de inicio de la palabra en la cadena.
 * @param {size_t} finish
 *      - The ending index of the word in the string. / 
 * 		El índice de finalización de la palabra en la cadena.
 * @return {char *}
 *      - A pointer to the newly allocated string containing the word. / 
 * 		Un puntero a la nueva cadena asignada que contiene la palabra.
 *      - NULL if memory allocation fails. / 
 * 		Un puntero a NULL si falla la asignación de memoria.
 */
static char	*ft_word_dup(const char *s, size_t start, size_t finish)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(finish - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

/*
 * ENGLISH: Counts the number of words in a string separated by a character.
 *
 * - Returns the count of words.
 *
 * SPANISH: Cuenta el número de palabras en una cadena separadas por un carácter.
 *
 * - Devuelve el recuento de palabras.
 *
 * @param {const char *} s
 *      - The string to count words in. / 
 * 		La cadena en la que contar palabras.
 * @param {char} c
 *      - The character that separates words. / 
 * 		El carácter que separa las palabras.
 * @return {size_t}
 *      - The number of words in the string. / 
 * 		El número de palabras en la cadena.
 */
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
			split[j++] = ft_word_dup(s, start, i);
	}
	split[j] = NULL;
	return (split);
}

/*
 * ENGLISH: Frees a split array of strings.
 *
 * - Iterates through the array and frees each string.
 * 
 * - Finally frees the array itself.
 *
 * SPANISH: Libera un arreglo dividido de cadenas.
 *
 * - Itera a través del arreglo y libera cada cadena.
 * 
 * - Finalmente libera el propio arreglo.
 *
 * @param {char **} split
 *      - The split array to free. / 
 * 		El arreglo dividido a liberar.
 */
void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
