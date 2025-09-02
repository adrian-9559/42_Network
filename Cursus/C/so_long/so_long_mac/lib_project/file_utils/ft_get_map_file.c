/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:52:13 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:07:00 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Appends a line to the map.
 *
 * SPANISH: Añade una línea al mapa.
 *
 * @param map   The map to modify. /
 *              El mapa a modificar.
 *
 * @param line  The line to append. /
 *              La línea a añadir.
 *
 * @param rows  The current number of rows in the map. /
 *              El número actual de filas en el mapa.
 *
 * @returns int
 *
 * - Returns 1 on success.
 *   Devuelve 1 en caso de éxito.
 *
 * - Returns 0 on failure.
 *   Devuelve 0 en caso de fallo.
 */
static int	ft_append_line(char ***map, char *line, int rows)
{
	char	**new_map;

	new_map = ft_realloc_map(*map, rows + 1);
	if (!new_map)
	{
		free(line);
		ft_free_map(*map, rows);
		return (0);
	}
	*map = new_map;
	(*map)[rows] = line;
	return (1);
}

/*
 * ENGLISH: Gets the map from a file.
 *
 * SPANISH: Obtiene el mapa de un archivo.
 *
 * @param filename   The name of the file to read. /
 *                   El nombre del archivo a leer.
 *
 * @param map        A pointer to the map to fill. /
 *                   Un puntero al mapa a llenar.
 *
 * @returns int
 *
 * - Returns the number of rows read on success.
 *   Devuelve el número de filas leídas en caso de éxito.
 *
 * - Returns -1 on failure.
 *   Devuelve -1 en caso de fallo.
 */
int	ft_get_map_file(const char *filename, char ***map)
{
	int		fd;
	char	*line;
	int		rows;

	fd = ft_open_file_read(filename);
	if (fd < 0)
		return (-1);
	rows = 0;
	*map = NULL;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		if (!ft_append_line(map, line, rows))
			return (-1);
		rows++;
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (rows);
}
