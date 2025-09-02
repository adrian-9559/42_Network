/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:28:46 by adriescr          #+#    #+#             */
/*   Updated: 2025/09/02 16:03:56 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Opens a file for reading.
 *
 * SPANISH: Abre un archivo para lectura.
 *
 * @param filename   The name of the file to open. /
 *                   El nombre del archivo a abrir.
 *
 * @returns The file descriptor for the opened file, or -1 on failure. /
 *          El descriptor de archivo para el archivo abierto, o -1 en 
 * 			caso de error.
 */
int	ft_open_file_read(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

/*
 * ENGLISH: Opens a file for writing.
 *
 * SPANISH: Abre un archivo para escritura.
 *
 * @param filename   The name of the file to open. /
 *                   El nombre del archivo a abrir.
 *
 * @returns The file descriptor for the opened file, or -1 on failure. /
 *          El descriptor de archivo para el archivo abierto, o -1 en 
 * 			caso de error.
 */
int	ft_open_file_write(const char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);
	return (fd);
}
