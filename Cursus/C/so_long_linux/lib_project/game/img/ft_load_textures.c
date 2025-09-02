/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:14:16 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:07:21 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Loads the textures for the game.
 *
 * SPANISH: Carga las texturas para el juego.
 *
 * @param game   The game instance. /
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
int	ft_load_textures(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->cols)
	{
		j = 0;
		while (j < game->rows)
		{
			if (ft_mlx_print_image(game, i, j) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
