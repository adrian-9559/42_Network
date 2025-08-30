/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:11:59 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/30 14:47:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_find_player_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (ft_putstr_error("Error\n Function: ft_find_player\n"
			"	Player position not found in map.\n"), -1);
}
