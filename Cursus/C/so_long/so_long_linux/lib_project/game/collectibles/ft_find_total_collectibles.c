/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_total_collectibles.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:36:48 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:07:11 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Finds the total number of collectibles in the game.
 *
 * SPANISH: Encuentra el número total de coleccionables en el juego.
 *
 * @param game   The game instance. /
 *               La instancia del juego.
 *
 * @returns int
 *
 * - Returns 0 on success.
 *   Devuelve 0 en caso de éxito.
 *
 * - Returns -1 on failure.
 *   Devuelve -1 en caso de fallo.
 */
int	ft_find_total_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	game->total_collectibles = count;
	return (0);
}
