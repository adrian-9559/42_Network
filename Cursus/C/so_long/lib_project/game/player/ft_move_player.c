/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:33:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 15:17:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_move_player(t_game *game, int new_x, int new_y)
{
	printf("Movimiento\n");
	printf("Player to go: %d %d map: %c\n", new_x, new_y, game->map[new_x][new_y]);
	if (game->map[new_x][new_y] == 'C')
	{
		game->collectibles++;
		game->map[new_x][new_y] = '0';
	}
	if (game->map[new_x][new_y] == 'E')
	{
		if (game->collectibles == game->total_collectibles)
		{
			ft_close_game(game);
			exit(0);
		}
		else
			return (0);
	}
	// Set previous player position to '0'
	game->map[game->player_x][game->player_y] = '0';
	// Update player coordinates
	game->player_x = new_x;
	game->player_y = new_y;
	// Set new player position to 'P'
	game->map[game->player_x][game->player_y] = 'P';
	return (0);
}
