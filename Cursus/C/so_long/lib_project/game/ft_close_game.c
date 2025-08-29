/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:18:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 16:24:09 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_map(game->map, game->rows);
	free(game);
	return (0);
}
