/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_file_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:11:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/02 15:46:17 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Saves the map to a file.
 *
 * SPANISH: Guarda el mapa en un archivo.
 *
 * @param filename  The name of the file to save the map.
 *                  El nombre del archivo para guardar el mapa.
 *
 * @param map      The map to save.
 *                 El mapa a guardar.
 *
 * @param rows     The number of rows in the map.
 *                 El número de filas en el mapa.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if an error occurs.
 *   -1 si ocurre un error.
 */
int	ft_save_map_to_file(const char *filename, char **map, int rows)
{
	int		fd;
	int		i;
	int		len;
	int		written;

	fd = ft_open_file_write(filename);
	if (fd < 0)
		return (ft_putstr_error("Error 8.1: Error opening file\n"), -1);
	i = 0;
	while (i < rows)
	{
		len = 0;
		while (map[i][len])
			len++;
		written = write(fd, map[i], len);
		if (written != len)
		{
			close(fd);
			return (ft_putstr_error("Error 8.2: Error writing to file\n"), -1);
		}
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	return (0);
}
