/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:45:58 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:01:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Frees all allocated memory for an array of strings.
 *
 * SPANISH: Libera toda la memoria asignada para un array de cadenas.
 *
 * @param arr   The array of strings to free. /
 *              El array de cadenas a liberar.
 * @param j     The number of strings in the array. /
 *              El número de cadenas en el array.
 *
 * @returns NULL. /
 *          NULL.
 */
static void	*free_all(char **arr, size_t j)
{
	while (j > 0)
		free(arr[--j]);
	free(arr);
	return (NULL);
}

/*
 * ENGLISH: Splits a string into an array of strings.
 *
 * SPANISH: Divide una cadena en un array de cadenas.
 *
 * @param s   The string to split. /
 *            La cadena a dividir.
 * @param c   The delimiter character. /
 *            El carácter delimitador.
 *
 * @returns A NULL-terminated array of strings on success, NULL on failure. /
 *          Un array de cadenas terminado en NULL en caso de éxito, NULL en caso de error.
 */
char	**ft_split(char const *s, char c)
{
	size_t	vars[4];
	char	**res;

	vars[0] = 0;
	vars[1] = 0;
	vars[2] = ft_count_words(s, c);
	res = malloc((vars[2] + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (vars[1] < vars[2])
	{
		while (s[vars[0]] == c)
			vars[0]++;
		vars[3] = vars[0];
		while (s[vars[0]] && s[vars[0]] != c)
			vars[0]++;
		res[vars[1]] = malloc(vars[0] - vars[3] + 1);
		if (!res[vars[1]])
			return (free_all(res, vars[1]));
		ft_memcpy(res[vars[1]], s + vars[3], vars[0] - vars[3]);
		res[vars[1]][vars[0] - vars[3]] = '\0';
		vars[1]++;
	}
	res[vars[1]] = NULL;
	return (res);
}
