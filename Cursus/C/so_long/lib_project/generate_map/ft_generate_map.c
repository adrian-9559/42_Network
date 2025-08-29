/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:03:06 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:56:26 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

static int	ft_allocate_map_rows(char **map, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		map[i] = malloc(sizeof(char) * (cols + 1));
		if (!map[i])
		{
			while (i > 0)
			{
				free(map[i - 1]);
				i--;
			}
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_generate_map(const char *filename)
{
	int				rows_cols[2];
	char			**map;
	unsigned int	seed;

	rows_cols[0] = MAP_ROWS;
	rows_cols[1] = MAP_COLS;
	seed = 42;
	map = malloc(sizeof(char *) * rows_cols[0]);
	if (!map)
		return (ft_putstr_error("Error\n Function: ft_generate_map\n"
				" Allocating memory for map.\n"),
			-1);
	if (ft_allocate_map_rows(map, rows_cols[0], rows_cols[1]) < 0)
		return (ft_putstr_error("Error\n Function: ft_generate_map\n"
				" Allocating memory for map rows.\n"),
			free(map), -1);
	if (ft_generate_map_rand_internal(rows_cols, map, seed, 0) < 0)
		return (-1);
	if (ft_save_map_to_file(filename, map, rows_cols[0]) < 0)
		return (ft_putstr_error("Error\n Function: ft_generate_map\n"
				" Error saving map to file.\n"), -1);
	return (0);
}

static int	ft_reset_map_rows(int *rows_cols, char **map)
{
	int	i;

	i = 0;
	while (i < rows_cols[0])
	{
		if (map[i])
			free(map[i]);
		map[i] = malloc(sizeof(char) * (rows_cols[1] + 1));
		if (!map[i])
			return (ft_putstr_error(
					"Error\n Function: ft_reset_map_rows\n"
					" Allocating memory for map row.\n"
				), -1);
		i++;
	}
	return (0);
}

int	ft_generate_map_rand_internal(int *rows_cols, char **map,
	unsigned int seed, int attempt)
{
	unsigned int	local_seed;

	if (attempt > MAX_MAP_GEN_ATTEMPTS)
		return (-1);
	local_seed = seed + ft_better_seed();
	ft_generate_simple_map(rows_cols, map, local_seed);
	ft_place_random_entities(rows_cols, map, &local_seed);
	if (ft_checker_posible_complete(map, rows_cols[0]) < 0)
	{
		if (ft_reset_map_rows(rows_cols, map) < 0)
			return (-1);
		return (ft_generate_map_rand_internal(rows_cols, map,
				seed, attempt + 1));
	}
	return (ft_checker_map_empty_rows(map));
}
