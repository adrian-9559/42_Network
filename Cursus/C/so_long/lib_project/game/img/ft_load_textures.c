/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:14:16 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 13:39:21 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_load_textures(t_game *game)
{
	int	i;
	int	j;

	printf("Loading textures...\n");
	i = 0;
	while (i < game->cols)
	{
		j = 0;
		while (j < game->rows)
		{
			if (ft_mlx_print_image(game, i, j) < 0)
				return (-1);
			printf("Texture loaded at: %d %d\n", i, j);
			j++;
		}
		i++;
	}
	printf("All textures loaded successfully.\n");
	return (0);
}
