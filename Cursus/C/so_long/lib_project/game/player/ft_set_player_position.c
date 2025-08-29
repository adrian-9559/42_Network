/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_player_position.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:31:30 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:59:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_set_player_position(t_game *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	if (!game->player_x || !game->player_y)
		return (ft_putstr_error("Error\n Function: ft_set_player_position\n"
				"	Player position not set in map.\n"), -1);
	return (0);
}
