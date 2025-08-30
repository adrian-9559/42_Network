/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:18:24 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 13:20:44 by adriescr         ###   ########.fr       */
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
	printf("Game collectibles: %d\n", game->total_collectibles);
	// Game loop and other logic would go here
	mlx_hook(game->win, 2, 1L << 0, ft_key_press, game);
	mlx_hook(game->win, 17, 1L << 17, ft_close_game, game);
	mlx_loop_hook(game->mlx, ft_load_textures, game);
	mlx_loop(game->mlx);
	// Only free resources after the loop ends
	ft_close_game(game);
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	if (!game)
		return (0);
	printf("Player position: (%d, %d)\n", game->player_x, game->player_y);
	printf("Player: %d %d\n", game->player_x, game->player_y);
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_W)
	{
		if (ft_move_player(game, game->player_x - 1, game->player_y) < 0)
			return (-1);
	} // Arriba
	else if (keycode == KEY_A)
	{
		if (ft_move_player(game, game->player_x, game->player_y - 1) < 0)
			return (-1);
	} // Izquierda
	else if (keycode == KEY_S)
	{
		if (ft_move_player(game, game->player_x + 1, game->player_y) < 0)
			return (-1);
	} // Abajo
	else if (keycode == KEY_D)
	{
		if (ft_move_player(game, game->player_x, game->player_y + 1) < 0)
			return (-1);
	} // Derecha
	else if (keycode == KEY_ESC)
	{
		ft_close_game(game);
		return (-1);
	}
	return (0);
}
