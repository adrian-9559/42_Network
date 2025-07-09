/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:15:00 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 16:58:16 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

unsigned int	ft_better_seed(void)
{
	static unsigned int	counter;

	counter = 0;
	counter += 12345;
	return ((unsigned int)((unsigned long)&counter ^ counter));
}

static void	ft_place_entity(int *rows_cols, char **map,
	unsigned int *seed, char entity)
{
	int	i;
	int	j;

	while (1)
	{
		i = rand_r(seed) % rows_cols[0];
		j = rand_r(seed) % rows_cols[1];
		if (map[i][j] == '0')
		{
			map[i][j] = entity;
			return ;
		}
	}
}

void	ft_place_random_entities(int *rows_cols, char **map,
	unsigned int *seed)
{
	int	collectibles;

	collectibles = 3;
	ft_place_entity(rows_cols, map, seed, 'P');
	ft_place_entity(rows_cols, map, seed, 'E');
	while (collectibles-- > 0)
		ft_place_entity(rows_cols, map, seed, 'C');
}
