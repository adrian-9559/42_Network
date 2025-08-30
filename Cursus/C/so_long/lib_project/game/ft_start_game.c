/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia <agarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:57:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 15:58:30 by agarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

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
	if (ft_init_mlx(game) < 0)
	{
		ft_free_map(game->map, game->rows);
		free(game);
		return (-1);
	}
	return (0);
}

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
	if (ft_init_mlx_texture(game) < 0)
		return (-1);
	return (0);
}
