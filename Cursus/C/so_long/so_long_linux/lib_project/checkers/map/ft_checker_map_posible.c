/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_map_posible.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 03:18:37 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:06:10 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Duplicates a 2D matrix.
 *
 * SPANISH: Duplica una matriz 2D.
 *
 * @param matrix   The matrix to duplicate. /
 *                 La matriz a duplicar.
 *
 * @param rows     The number of rows in the matrix. /
 *                 El número de filas en la matriz.
 *
 * @returns char**
 *
 * - Returns a pointer to the duplicated matrix.
 *   Devuelve un puntero a la matriz duplicada.
 *
 * - Returns NULL on failure.
 *   Devuelve NULL en caso de fallo.
 */
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

/*
 * ENGLISH: Finds the player's position in the map.
 *
 * SPANISH: Encuentra la posición del jugador en el mapa.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @param rows  The number of rows in the map. /
 *              El número de filas en el mapa.
 *
 * @param px    Pointer to store the player's x position. /
 *               Puntero para almacenar la posición x del jugador.
 *
 * @param py    Pointer to store the player's y position. /
 *               Puntero para almacenar la posición y del jugador.
 *
 * @returns int
 *
 * - Returns 0 if the player is found.
 *   Devuelve 0 si se encuentra al jugador.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
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

/*
 * ENGLISH: Flood fills the map from the player's position.
 *
 * SPANISH: Rellena el mapa desde la posición del jugador.
 *
 * @param map   The map to fill. /
 *              El mapa a rellenar.
 *
 * @param x     The x position to start filling from. /
 *              La posición x desde la que comenzar a rellenar.
 *
 * @param y     The y position to start filling from. /
 *              La posición y desde la que comenzar a rellenar.
 *
 * @param rows  The number of rows in the map. /
 *              El número de filas en el mapa.
 */
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

/*
 * ENGLISH: Checks for unreachable elements in the map.
 *
 * SPANISH: Verifica si hay elementos inalcanzables en el mapa.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @param rows  The number of rows in the map. /
 *              El número de filas en el mapa.
 *
 * @returns int
 *
 * - Returns 0 if all elements are reachable.
 *   Devuelve 0 si todos los elementos son alcanzables.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
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

/*
 * ENGLISH: Checks if the map is complete.
 *
 * SPANISH: Verifica si el mapa está completo.
 *
 * @param map   The map to check. /
 *              El mapa a verificar.
 *
 * @param rows  The number of rows in the map. /
 *              El número de filas en el mapa.
 *
 * @returns int
 *
 * - Returns 0 if the map is complete.
 *   Devuelve 0 si el mapa está completo.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
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
