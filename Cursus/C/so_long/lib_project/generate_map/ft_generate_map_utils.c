/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_map_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:15:00 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:16:21 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Returns a better seed for random number generation.
 *
 * SPANISH: Devuelve una mejor semilla para la generación de números aleatorios.
 *
 * @returns unsigned int
 */
unsigned int	ft_better_seed(void)
{
	static unsigned int	counter;

	counter = 0;
	counter += 12345;
	return ((unsigned int)((unsigned long)&counter ^ counter));
}

/*
 * ENGLISH: Places an entity on the map.
 *
 * SPANISH: Coloca una entidad en el mapa.
 *
 * @param rows_cols  The dimensions of the map.
 *                   Las dimensiones del mapa.
 *
 * @param map       The map to modify.
 *                  El mapa a modificar.
 *
 * @param seed      The seed for random number generation.
 *                  La semilla para la generación de números aleatorios.
 *
 * @param entity    The entity to place.
 *                  La entidad a colocar.
 */
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

/*
 * ENGLISH: Places random entities on the map.
 *
 * SPANISH: Coloca entidades aleatorias en el mapa.
 *
 * @param rows_cols  The dimensions of the map.
 *                   Las dimensiones del mapa.
 *
 * @param map       The map to modify.
 *                  El mapa a modificar.
 *
 * @param seed      The seed for random number generation.
 *                  La semilla para la generación de números aleatorios.
 */
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
