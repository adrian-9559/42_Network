/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map_empty.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:21:35 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:05:11 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Checks if the map has empty rows.
 *
 * SPANISH: Verifica si el mapa tiene filas vacías.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @returns int
 *
 * - Returns 0 if the map has no empty rows.
 *   Devuelve 0 si el mapa no tiene filas vacías.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
int	ft_checker_map_empty_rows(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\0')
		{
			j = 0;
			while (map[j])
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (-1);
		}
		i++;
	}
	return (0);
}
