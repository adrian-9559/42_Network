/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:54:27 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:04:29 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Checks if the file exists.
 *
 * SPANISH: Verifica si el archivo existe.
 *
 * @param filename   The name of the file to check. /
 *                   El nombre del archivo a verificar.
 *
 * @returns int
 *
 * - Returns 0 if the file exists.
 *   Devuelve 0 si el archivo existe.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
int	ft_checker_file_exists(const char *filename)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file >= 0)
	{
		close(file);
		return (0);
	}
	else
	{
		ft_putstr_error("Error\n Function: ft_checker_file_exists\n	"
			"	File does not exist.\n");
		return (-1);
	}
}
