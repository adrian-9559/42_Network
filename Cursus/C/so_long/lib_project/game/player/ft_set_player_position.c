/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:31:30 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:14:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Sets the player's position in the game.
 *
 * SPANISH: Establece la posición del jugador en el juego.
 *
 * @param game   	The game instance.
 *               	La instancia del juego.
 *
 * @param x       The x-coordinate to set for the player.
 *                La coordenada x a establecer para el jugador.
 *
 * @param y       The y-coordinate to set for the player.
 *                La coordenada y a establecer para el jugador.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if the position is invalid.
 *   -1 si la posición es inválida.
 */
int	ft_set_player_position(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	if (!game->player_x || !game->player_y)
		return (ft_putstr_error("Error\n Function: ft_set_player_position\n"
				"	Player position not set in map.\n"), -1);
	return (0);
}
