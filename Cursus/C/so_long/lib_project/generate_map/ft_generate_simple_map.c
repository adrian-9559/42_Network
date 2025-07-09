/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_simple_map.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:44:05 by adriescr          #+#    #+#             */
/*   Updated: 2025/07/09 18:17:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

void	ft_generate_simple_map(int *rows_cols, char **map,
			unsigned int seed)
{
	int				cont[2];
	unsigned int	local_seed;

	local_seed = seed;
	cont[0] = 0;
	while (cont[0] < rows_cols[0])
	{
		cont[1] = 0;
		while (cont[1] < rows_cols[1])
		{
			if (cont[0] == 0 || cont[0] == rows_cols[0] - 1 || cont[1] == 0
				|| cont[1] == rows_cols[1] - 1)
				map[cont[0]][cont[1]] = '1';
			else
			{
				if (ft_simple_rand(&local_seed) % 5 == 0)
					map[cont[0]][cont[1]] = '1';
				else
					map[cont[0]][cont[1]] = '0';
			}
			cont[1]++;
		}
		map[cont[0]][rows_cols[1]] = '\0';
		cont[0]++;
	}
}
