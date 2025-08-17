/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 13:51:45 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 14:48:27 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

/*
 * ENGLISH: Opens a file with the specified name and mode.
 *
 * SPANISH: Abre un archivo con el nombre y modo especificados.
 *
 * @param filename   
 * 					The name of the file to open. / 
 * 					El nombre del archivo a abrir.
 * @param in_or_out  
 * 					Specifies whether the file is for input (0) or output (1). / 
 * 					Especifica si el archivo es para entrada (0) o salida (1).
 *
 * @return {int}
 * 
 * - Returns the file descriptor if successful, or -1 on error.
 * 
 * - Devuelve el descriptor de archivo si tiene éxito, o -1 en caso de error.
 */
int	ft_open_fd(const char *filename, int in_or_out)
{
	int	flags;
	int	fd;

	if (in_or_out == 0)
		flags = O_RDONLY;
	else
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(filename, flags, 0644);
	if (fd == -1)
	{
		close(fd);
		perror("Error opening file");
		exit(EXIT_FAILURE);
		return (-1);
	}
	return (fd);
}
