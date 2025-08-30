/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:18:24 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 15:13:11 by adriescr         ###   ########.fr       */
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
	mlx_do_sync(game->mlx);
	mlx_hook(game->win, 2, 1L, ft_key_press, game);
	mlx_hook(game->win, 17, 1L, ft_close_game, game);
	mlx_loop_hook(game->mlx, ft_load_textures, game);
	mlx_loop(game->mlx);
	// Resources are freed in ft_close_game via the hook, so no need to call it here
	return (0);
}

int ft_is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->rows || y < 0 || y >= game->cols)
		return (0);
	if (game->map[x][y] == 1)
	{
		ft_putstr("Move blocked by wall.\n");
		return (0);
	}
	return (1);
}

int	ft_key_press(int keycode, t_game *game)
{
	int	new_player_x;
	int	new_player_y;

	if (!game)
		return (0);
	new_player_x = game->player_x;
	new_player_y = game->player_y;

	printf("Player position: (%d, %d)\n", game->player_x, game->player_y);
	printf("Player: %d %d\n", game->player_x, game->player_y);
	printf("keycode: %d\n", keycode);
	if (keycode == KEY_W)
	{
		new_player_x--;
		if (ft_is_valid_move(game, new_player_x, new_player_y))
			ft_move_player(game, new_player_x, new_player_y);
	}
	else if (keycode == KEY_A)
	{
		new_player_y--;
		if (ft_is_valid_move(game, new_player_x, new_player_y))
			ft_move_player(game, new_player_x, new_player_y);
	}
	else if (keycode == KEY_S)
	{
		new_player_x++;
		if (ft_is_valid_move(game, new_player_x, new_player_y))
			ft_move_player(game, new_player_x, new_player_y);
	}
	else if (keycode == KEY_D)
	{
		new_player_y++;
		if (ft_is_valid_move(game, new_player_x, new_player_y))
			ft_move_player(game, new_player_x, new_player_y);
	}
	else if (keycode == KEY_ESC)
	{
		ft_close_game(game);
		return (-1);
	}
	printf("Player: %d %d\n", game->player_x, game->player_y);
	return (0);
}

