/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_infile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:40:54 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:11:38 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
 * ENGLISH: Opens an input file with the specified name.
 *
 * SPANISH: Abre un archivo de entrada con el nombre especificado.
 *
 * @param filename   
 * 					The name of the file to open. / 
 * 					El nombre del archivo a abrir.
 * @param infile_error
 * 					Error status for input file opening. / 
 * 					Estado de error al abrir el archivo de entrada.
 *
 * @return {int}
 * 
 * - Returns the file descriptor if successful, or -1 on error.
 * 
 * - Devuelve el descriptor de archivo si tiene éxito, o -1 en caso de error.
 */
int	ft_open_infile(const char *filename, int *infile_error)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "pipex: ", 7);
		perror(filename);
		*infile_error = 1;
	}
	return (fd);
}
