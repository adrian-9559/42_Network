/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map_posible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 03:18:37 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/29 21:54:59 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

char	**ft_strdup_matrix(char **matrix, int rows)
{
	char	**dup;
	int		i;

	if (!matrix)
		return (NULL);
	dup = malloc(sizeof(char *) * (rows + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dup[i] = ft_strdup(matrix[i]);
		if (!dup[i])
		{
			while (--i >= 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[rows] = NULL;
	return (dup);
}

static int	ft_find_player(char **map, int rows, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

static void	ft_flood_fill(char **map, int x, int y, int rows)
{
	if (y < 0 || x < 0 || !map[y] || map[y][x] == '1'
		|| map[y][x] == 'V' || map[y][x] == '\0')
		return ;
	map[y][x] = 'V';
	ft_flood_fill(map, x + 1, y, rows);
	ft_flood_fill(map, x - 1, y, rows);
	ft_flood_fill(map, x, y + 1, rows);
	ft_flood_fill(map, x, y - 1, rows);
}

static int	ft_check_unreachable_elements(char **map, int rows)
{
	int	row;
	int	col;

	row = 0;
	while (row < rows)
	{
		col = 0;
		while (map[row][col])
		{
			if ((map[row][col] == 'C' || map[row][col] == 'E')
				&& map[row][col] != 'V')
				return (-1);
			col++;
		}
		row++;
	}
	return (0);
}

int	ft_checker_posible_complete(char **map, int rows)
{
	char	**aux;
	int		x;
	int		y;
	int		result;

	aux = ft_strdup_matrix(map, rows);
	if (!aux)
		return (ft_putstr_error("Error\n Function: ft_checker_map_posible\n"
				" Memory allocation failed.\n"), -1);
	if (ft_find_player(aux, rows, &x, &y) < 0)
	{
		ft_putstr_error("Error\n Function: ft_checker_map_posible\n"
			" Player not found in the map.\n");
		ft_free_map(aux, rows);
		return (-1);
	}
	ft_flood_fill(aux, x, y, rows);
	result = ft_check_unreachable_elements(aux, rows);
	ft_free_map(aux, rows);
	return (result);
}
