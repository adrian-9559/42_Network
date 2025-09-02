/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:33:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/02 15:58:35 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Moves the player to a new position in the game.
 *
 * SPANISH: Mueve al jugador a una nueva posición en el juego.
 *
 * @param game   	The game instance.
 *               	La instancia del juego.
 *
 * @param new_x   The new x-coordinate for the player.
 *                La nueva coordenada x para el jugador.
 *
 * @param new_y   The new y-coordinate for the player.
 *                La nueva coordenada y para el jugador.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if the move is invalid.
 *   -1 si el movimiento es inválido.
 */
int	ft_move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles++;
		game->map[new_y][new_x] = '0';
	}
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles == game->total_collectibles)
		{
			game->moves++;
			ft_close_game(game);
			exit(0);
		}
	}
	if (game->map[new_y][new_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[game->player_y][game->player_x] = 'P';
		game->moves++;
	}
	ft_putstr("\nMoves: ");
	ft_putnbr(game->moves);
	return (0);
}
