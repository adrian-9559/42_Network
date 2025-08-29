/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:57:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:58:09 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_start_game(const char *filename, t_game *game)
{
	game->map = NULL;
	game->rows = ft_get_map_file(filename, &(game->map));
	if (game->rows < 0)
		return (free(game), ft_putstr_error("Error\n Function: ft_start_game\n"
				"	Failed to load map file.\n"), -1);
	if (ft_init_game(game) < 0)
	{
		ft_free_map(game->map, game->rows);
		free(game);
		return (-1);
	}
	return (0);
}

int	ft_init_game(t_game *game)
{
	int	i;

	ft_putstr("Game initialized with map:\n");
	for (i = 0; i < game->rows; i++)
		ft_putstr(game->map[i]);
	ft_putstr("\n");
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_putstr_error("Error\n Function: ft_init_game\n"
				"	Failed to initialize mlx.\n"), -1);
	game->win = mlx_new_window(game->mlx, game->cols * TILE_SIZE,
			game->rows * TILE_SIZE, "So Long Game");
	if (!game->win)
		return (ft_putstr_error("Error\n Function: ft_init_game\n"
				"	Failed to create window.\n"), -1);
	if (ft_init_mlx_texture(game) < 0)
		return (-1);
	if (ft_load_textures(game) < 0)
		return (-1);
	return (0);
}

int	ft_key_press(int keycode, t_game *game)
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_esc;

	key_w = KEY_W;
	key_a = KEY_A;
	key_s = KEY_S;
	key_d = KEY_D;
	key_esc = KEY_ESC;
	if (keycode == key_w)
		return (ft_move_player(game, game->player_x - 1, game->player_y), 0);
	else if (keycode == key_a)
		return (ft_move_player(game, game->player_x, game->player_y - 1), 0);
	else if (keycode == key_s)
		return (ft_move_player(game, game->player_x + 1, game->player_y), 0);
	else if (keycode == key_d)
		return (ft_move_player(game, game->player_x, game->player_y + 1), 0);
	else if (keycode == key_esc)
		return (ft_close_game(game), -1);
	return (0);
}
