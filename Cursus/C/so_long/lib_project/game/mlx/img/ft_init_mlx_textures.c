/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:15:36 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 00:01:18 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../../so_long.h"

int	ft_init_mlx_texture(t_game *game)
{
	int		h_img;
	int		w_img;
	char	*img_floor;
	char	*img_wall;
	char	*img_exit;
	char	*img_collectibles;
	char	*img_player;

	h_img = HEIGHT_IMAGE;
	w_img = WIDTH_IMAGE;
	img_floor = FLOOR_FILE_NAME;
	img_wall = WALL_FILE_NAME;
	img_exit = EXIT_FILE_NAME;
	img_collectibles = COLLECTIBLES_FILE_NAME;
	img_player = PLAYER_FILE_NAME;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, img_wall, &w_img, &h_img);
	game->player_img = mlx_xpm_file_to_image(game->mlx, img_player, &w_img, &h_img);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, img_exit, &w_img, &h_img);
	game->collectibles_img = mlx_xpm_file_to_image(game->mlx, img_collectibles, &w_img, &h_img);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, img_floor, &w_img, &h_img);
	if (!game->wall_img || !game->player_img || !game->exit_img || !game->collectibles_img || !game->floor_img)
	{
		ft_putstr_error("Error\n Function: ft_init_mlx_texture\n	Failed to init textures.\n");
		return (-1);
	}
	return (0);
}
