/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:18:24 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 15:40:30 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_game(const char *filename)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_putstr_error("Error\n Function: ft_game\n"
								"	Memory allocation failed.\n"),
				-1);
	if (ft_start_game(filename, game) < 0)
		return (-1);
	mlx_do_sync(game->mlx);
	mlx_hook(game->win, 2, 1L, ft_key_press, game);
	mlx_hook(game->win, 17, 1L, ft_close_game, game);
	mlx_loop_hook(game->mlx, ft_load_textures, game);
	mlx_loop(game->mlx);
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (!game)
		return (0);
	if (keycode == KEY_W)
		ft_move_player(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_A)
		ft_move_player(game, game->player_x - 1, game->player_y);
	else if (keycode == KEY_S)
		ft_move_player(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_D)
		ft_move_player(game, game->player_x + 1, game->player_y);
	else if (keycode == KEY_ESC)
	{
		ft_close_game(game);
		return (-1);
	}
	return (0);
}
