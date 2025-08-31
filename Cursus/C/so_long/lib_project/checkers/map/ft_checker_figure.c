/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_figure.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:45:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:04:55 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Checks if the map is rectangular.
 *
 * SPANISH: Verifica si el mapa es rectangular.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @param rows  The number of rows in the map. /
 *              El número de filas en el mapa.
 *
 * @returns int
 *
 * - Returns 0 if the map is rectangular.
 *   Devuelve 0 si el mapa es rectangular.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
static int	ft_checker_rectangle(char **map, int rows)
{
	int	i;
	int	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (i < rows)
	{
		if ((int)ft_strlen(map[i]) != len)
			return (-1);
		i++;
	}
	return (0);
}

/*
 * ENGLISH: Checks if the map is valid.
 *
 * SPANISH: Verifica si el mapa es válido.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @param rows  The number of rows in the map. /
 *              El número de filas en el mapa.
 *
 * @returns int
 *
 * - Returns 0 if the map is valid.
 *   Devuelve 0 si el mapa es válido.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
int	ft_checker_figure(char **map, int rows)
{
	int	cols;

	cols = ft_small_map(map, rows) - 1;
	if (cols < 0)
		return (ft_putstr_error("Error\n Function: ft_checker_figure\n"
				"Map is too small.\n"), -1);
	if (ft_checker_wall(map, rows, cols) < 0)
		return (ft_putstr_error(
				"Error\n Function: ft_checker_figure\n"
				"	Map is not surrounded by walls.\n"), -1);
	if (ft_checker_rectangle(map, rows) < 0)
		return (ft_putstr_error("Error\n Function: ft_checker_figure\n"
				"	Map is not rectangular.\n"), -1);
	return (0);
}
