/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:51:13 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:17:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Frees the memory allocated for the map.
 *
 * SPANISH: Libera la memoria asignada para el mapa.
 *
 * @param map   The map to free.
 *              El mapa a liberar.
 *
 * @param rows  The number of rows in the map.
 *              El número de filas en el mapa.
 */
void	ft_free_map(char **map, int rows)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
