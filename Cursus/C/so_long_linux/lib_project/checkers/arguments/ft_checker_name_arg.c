/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_name_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:31:56 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:21:35 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Checks if the provided file name has a valid extension (.ber).
 *
 * SPANISH: Verifica si el nombre de archivo proporcionado 
 * 			tiene una extensión válida (.ber).
 *
 * @param str   The name of the file to check. /
 *              El nombre del archivo a verificar.
 *
 * @returns int
 *
 * - Returns 0 if the file name is valid.
 *   Devuelve 0 si el nombre del archivo es válido.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
int	ft_checker_name_arg(const char *str)
{
	size_t	len;

	if (!str)
	{
		ft_putstr_error("Error\n Function: ft_checker_name_arg\n"
			"	Invalid file name.\n");
		return (-1);
	}
	len = ft_strlen(str);
	if (len < 4 || str[len - 4] != '.' || str[len - 3] != 'b'
		|| str[len - 2] != 'e' || str[len - 1] != 'r')
	{
		ft_putstr_error("Error\n Function: ft_checker_name_arg\n"
			"	Invalid file extension.\n");
		return (-1);
	}
	return (0);
}
