/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:33:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 16:00:57 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

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
			ft_close_game(game);
			exit(0);
		}
		else
			return (0);
	}
	if (game->map[new_y][new_x] == '0')
	{
		game->map[game->player_y][game->player_x] = '0';
		// Update player coordinates
		game->player_x = new_x;
		game->player_y = new_y;
		// Set new player position to 'P'
		game->map[game->player_y][game->player_x] = 'P';
	}
	return (0);
}
