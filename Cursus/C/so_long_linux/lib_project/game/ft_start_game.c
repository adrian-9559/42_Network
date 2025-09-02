/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:57:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:15:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Starts the game.
 *
 * SPANISH: Inicia el juego.
 *
 * @param filename  The map file to load.
 *                  El archivo del mapa a cargar.
 *
 * @param game     The game instance.
 *                 La instancia del juego.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if initialization fails.
 *   -1 si la inicialización falla.
 */
int	ft_start_game(const char *filename, t_game *game)
{
	game->map = NULL;
	game->rows = ft_get_map_file(filename, &(game->map));
	if (game->rows < 0)
		return (free(game),
			ft_putstr_error("Error\n Function: ft_start_game\n"
				"	Failed to load map file.\n"),
			-1);
	game->cols = ft_strlen(game->map[0]) - 1;
	ft_find_total_collectibles(game);
	ft_find_player_game(game);
	game->moves = 0;
	if (ft_init_mlx(game) < 0)
	{
		ft_free_map(game->map, game->rows);
		free(game);
		return (-1);
	}
	return (0);
}

/*
 * ENGLISH: Initializes the mlx instance.
 *
 * SPANISH: Inicializa la instancia de mlx.
 *
 * @param game     The game instance.
 *                 La instancia del juego.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if initialization fails.
 *   -1 si la inicialización falla.
 */
int	ft_init_mlx(t_game *game)
{
	int	i;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_putstr_error("Error\n Function: ft_init_game\n"
				"	Failed to initialize mlx.\n"),
			-1);
	game->win = mlx_new_window(game->mlx, game->cols * TILE_SIZE, game->rows
			* TILE_SIZE, "./so_long");
	if (!game->win)
		return (ft_putstr_error("Error\n Function: ft_init_game\n"
				"	Failed to create window.\n"),
			-1);
	ft_init_mlx_texture(game);
	if (!game->wall_img || !game->player_img || !game->exit_img
		|| !game->collectibles_img || !game->floor_img)
		return (ft_putstr_error("Error\n Function: ft_init_mlx_texture\n"
				"	Failed to init textures.\n"), -1);
	return (0);
}
