/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:57:52 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:17:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Checks if the map is too small.
 *
 * SPANISH: Verifica si el mapa es demasiado pequeño.
 *
 * @param map   The map to check.
 *              El mapa a verificar.
 *
 * @param rows  The number of rows in the map.
 *              El número de filas en el mapa.
 *
 * @returns int
 *
 * - The number of columns if the map is not too small.
 *   El número de columnas si el mapa no es demasiado pequeño.
 *
 * - -1 if the map is too small.
 *   -1 si el mapa es demasiado pequeño.
 */
int	ft_small_map(char **map, int rows)
{
	int	cols;

	cols = ft_strlen(map[0]);
	if ((cols <= 3 && rows <= 5) || (cols <= 5 && rows <= 3))
		return (-1);
	return (cols);
}
