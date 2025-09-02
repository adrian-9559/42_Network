/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:04:22 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:15:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../so_long.h"

/*
 * ENGLISH: Generates a new map file.
 *
 * SPANISH: Genera un nuevo archivo de mapa.
 *
 * @param filename  The name of the file to create.
 *                  El nombre del archivo a crear.
 *
 * @returns int
 *
 * - The file descriptor on success.
 *   El descriptor de archivo en caso de éxito.
 *
 * - -1 if an error occurs.
 *   -1 si ocurre un error.
 */
int	ft_generate_file(const char *filename)
{
	int	file;

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (!file)
		return (ft_putstr_error("Error\n Function: ft_generate\n"
				" Could not create file.\n"), -1);
	ft_putstr("\033[0;32mMap file generated successfully.\033[0m\n");
	return (file);
}
