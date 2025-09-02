/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:18:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:14:58 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Closes the game and frees resources.
 *
 * SPANISH: Cierra el juego y libera recursos.
 *
 * @param game   	The game instance.
 *               	La instancia del juego.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if the game instance is invalid.
 *   -1 si la instancia del juego es inválida.
 */
int	ft_close_game(t_game *game)
{
	if (game && game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game && game->map)
		ft_free_map(game->map, game->rows);
	free(game);
	exit(0);
	return (-1);
}
