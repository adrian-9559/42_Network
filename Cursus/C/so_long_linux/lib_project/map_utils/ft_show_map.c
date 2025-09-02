/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:15:12 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:17:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Displays the map.
 *
 * SPANISH: Muestra el mapa.
 *
 * @param map   The map to display.
 *              El mapa a mostrar.
 *
 * @param rows  The number of rows in the map.
 *              El número de filas en el mapa.
 */
void	ft_show_map(char **map, int rows)
{
	int	i;

	if (!map || rows <= 0)
		return ;
	i = 0;
	while (i < rows)
	{
		ft_putstr(map[i]);
		i++;
	}
}
