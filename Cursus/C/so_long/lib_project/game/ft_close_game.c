/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:18:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 13:21:09 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

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
