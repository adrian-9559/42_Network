/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:57:08 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/29 15:46:19 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

int	ft_start_game(const char *filename)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_putstr_error("Error 13: Memory allocation failed.\n"), -1);
	game->rows = ft_get_map_file(filename, game->map);
	if (game->rows < 0)
		return (free(game), ft_putstr_error("Error 14: Failed to load map file.\n"), -1);
		/*
	if (ft_init_game(game) < 0)
	{
		ft_putstr_error("Error 15: Failed to initialize game.\n");
		ft_free_map(game->map, game->rows);
		free(game);
		return (-1);
	}*/
	free(game);
	return (0);
}

/*
int	ft_init_game(t_game *game)
{
	int i;
	ft_putstr("Game initialized with map:\n");
	for (i = 0; i < game->rows; i++)
		ft_putstr(game->map[i]);
	ft_putstr("\n");

	if (ft_load_textures() < 0)
	{
		ft_putstr_error("Error 16: Failed to load textures.\n");
		ft_free_map(game->map, game->rows);
		return (-1);
	}
	if (ft_setup_player() < 0)
	{
		ft_putstr_error("Error 17: Failed to set up player.\n");
		ft_free_map(game->map, game->rows);
		return (-1);
	}
	return (0);
}

int	ft_load_textures(void)
{
	void	*mlx_ptr;
	int		width;
	int		height;
	
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	{
		ft_putstr_error("Error 18: Failed to initialize mlx.\n");
		return (-1);
	}
	width = 0;
	height = 0;
	// Load textures for the game
	if (mlx_xpm_file_to_image(mlx_ptr, FLOOR_FILE_NAME, &width, &height) == NULL)
	{
		ft_putstr_error("Error 18: Failed to load floor texture.\n");
		return (-1);
	}
	if (mlx_xpm_file_to_image(mlx_ptr, WALL_FILE_NAME, &width, &height) == NULL)
	{
		ft_putstr_error("Error 19: Failed to load wall texture.\n");
		return (-1);
	}
	return (0);
}
*/