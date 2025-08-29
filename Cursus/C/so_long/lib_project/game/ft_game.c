/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:18:24 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 22:07:35 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_game(const char *filename)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_putstr_error("Error\n Function: ft_game\n"
				"	Memory allocation failed.\n"), -1);
	if (ft_start_game(filename, game) < 0)
		return (-1);
	// Game loop and other logic would go here
	mlx_hook(game->win, 2, 1L, ft_key_press, game);
	mlx_hook(game->win, 17, 1L, ft_close_game, game);
	mlx_loop(game->mlx);
	ft_close_game(game);
	return (0);
}
