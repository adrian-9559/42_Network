/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:00:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:06:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Checks if the walls of the map are intact.
 *
 * SPANISH: Verifica si las paredes del mapa están intactas.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @param rows  The number of rows in the map. /
 *              El número de filas en el mapa.
 *
 * @param cols  The number of columns in the map. /
 *              El número de columnas en el mapa.
 *
 * @returns int
 *
 * - Returns 0 if the walls are intact.
 *   Devuelve 0 si las paredes están intactas.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
int	ft_checker_wall(char **map, int rows, int cols)
{
	int	j;

	j = 0;
	while (j < cols)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (j < rows)
	{
		if (map[j][0] != '1' || map[j][cols - 1] != '1')
			return (-1);
		j++;
	}
	return (0);
}
