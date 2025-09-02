/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mlx_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:10:29 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:14:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../../so_long.h"

/*
 * ENGLISH: Prints an image using the MLX library.
 *
 * SPANISH: Imprime una imagen usando la biblioteca MLX.
 *
 * @param game   	The game instance.
 *               	La instancia del juego.
 *
 * @param x         The x-coordinate where the image will be printed.
 *                  La coordenada x donde se imprimirá la imagen.
 *
 * @param y         The y-coordinate where the image will be printed.
 *                  La coordenada y donde se imprimirá la imagen.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 */
int	ft_mlx_print_image(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectibles_img,
			x * TILE_SIZE, y * TILE_SIZE);
	return (0);
}
