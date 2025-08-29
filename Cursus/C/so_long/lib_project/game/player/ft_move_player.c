/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:33:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 15:23:01 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_x][new_y] == '1')
		return (0);
	if (game->map[new_x][new_y] == 'C')
		ft_collect_prize(game, new_x, new_y);
	game->map[game->player_x][game->player_y] = '0';
	game->map[new_x][new_y] = 'P';
	ft_set_player_position(game, new_x, new_y);
	ft_mlx_print_image(game, new_x, new_y);
	return (0);
}
