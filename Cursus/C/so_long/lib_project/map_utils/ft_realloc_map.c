/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:50:45 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:17:22 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Reallocates the memory for the map.
 *
 * SPANISH: Reasigna la memoria para el mapa.
 *
 * @param map      The map to reallocate.
 *                 El mapa a reasignar.
 *
 * @param new_size The new size of the map.
 *                 El nuevo tamaño del mapa.
 *
 * @returns char**
 *
 * - The reallocated map on success.
 *   El mapa reasignado en caso de éxito.
 *
 * - NULL if an error occurs.
 *   NULL si ocurre un error.
 */
char	**ft_realloc_map(char **map, int new_size)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (new_size + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < new_size - 1 && map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = NULL;
	free(map);
	return (new_map);
}
