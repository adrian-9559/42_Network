/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:37:54 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:17:05 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Generates a new map.
 *
 * SPANISH: Genera un nuevo mapa.
 *
 * @param filename  The name of the file to create.
 *                  El nombre del archivo a crear.
 *
 * @returns int
 *
 * - 0 on success.
 *   0 en caso de éxito.
 *
 * - -1 if an error occurs.
 *   -1 si ocurre un error.
 */
int	ft_generate(const char *filename)
{
	int	fd;

	fd = ft_open_file_read(filename);
	if (fd < 0)
		if (ft_generate_file(filename) < 0)
			return (-1);
	close(fd);
	if (ft_generate_map(filename) > 0)
		return (-1);
	return (0);
}
