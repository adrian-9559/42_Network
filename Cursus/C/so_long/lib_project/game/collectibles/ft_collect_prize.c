/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_prize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:36:48 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:58:41 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

int	ft_collect_prize(t_game *game, int new_x, int new_y)
{
	game->map[new_x][new_y] = '0';
	game->collectibles--;
	return (0);
}
