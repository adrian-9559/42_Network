/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:11:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:14:30 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Finds the player's position in the game.
 *
 * SPANISH: Encuentra la posición del jugador en el juego.
 *
 * @param game   	The game instance.
 *               	La instancia del juego.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if the player is not found.
 *   -1 si no se encuentra el jugador.
 */
int	ft_find_player_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (ft_putstr_error("Error\n Function: ft_find_player\n"
			"	Player position not found in map.\n"), -1);
}
