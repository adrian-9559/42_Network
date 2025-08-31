/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:15:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:12:35 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../../so_long.h"

/*
 * ENGLISH: Initializes the textures for the game using the MLX library.
 *
 * SPANISH: Inicializa las texturas para el juego usando la biblioteca MLX.
 *
 * @param game   The game instance.
 *               La instancia del juego.
 *
 * @returns int
 *
 * - Returns 0 on success.
 *   Devuelve 0 en caso de éxito.
 *
 * - Returns -1 on failure.
 *   Devuelve -1 en caso de fallo.
 */
int	ft_init_mlx_texture(t_game *game)
{
	int		h_img;
	int		w_img;
	char	*img_files[5];

	h_img = HEIGHT_IMAGE;
	w_img = WIDTH_IMAGE;
	img_files[0] = FLOOR_FILE_NAME;
	img_files[1] = WALL_FILE_NAME;
	img_files[2] = EXIT_FILE_NAME;
	img_files[3] = COLLECTIBLES_FILE_NAME;
	img_files[4] = PLAYER_FILE_NAME;
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			img_files[1], &w_img, &h_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			img_files[4], &w_img, &h_img);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			img_files[2], &w_img, &h_img);
	game->collectibles_img = mlx_xpm_file_to_image(game->mlx,
			img_files[3], &w_img, &h_img);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			img_files[0], &w_img, &h_img);
	return (0);
}
