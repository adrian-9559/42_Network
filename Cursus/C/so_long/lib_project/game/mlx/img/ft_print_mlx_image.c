/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mlx_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:10:29 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:59:13 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../../so_long.h"

int	ft_mlx_print_image(t_game *game, int x, int y)
{
	int	t_size;

	t_size = TILE_SIZE;
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * t_size, y * t_size);
	else if (game->map[y][x] == 'P')
	{
		if (ft_set_player_position(game, x, y) < 0)
			return (-1);
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * t_size, y * t_size);
	}
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * t_size, y * t_size);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectibles_img, x * t_size, y * t_size);
	return (0);
}
