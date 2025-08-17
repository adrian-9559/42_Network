/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_outfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:38:11 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/17 15:12:54 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

/*
 * ENGLISH: Opens an output file with the specified name.
 *
 * SPANISH: Abre un archivo de salida con el nombre especificado.
 *
 * @param filename   
 * 					The name of the file to open. / 
 * 					El nombre del archivo a abrir.
 * @param infile     
 * 					File descriptor for the input file. / 
 * 					Descriptor de archivo para el archivo de entrada.
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
int	ft_open_outfile(const char *filename, int infile, int infile_error)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		write(2, "pipex: ", 7);
		perror(filename);
		if (!infile_error)
			close(infile);
	}
	return (fd);
}
