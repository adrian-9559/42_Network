/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_num_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 13:35:10 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:04:17 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../so_long.h"

/*
 * ENGLISH: Checks if the number of arguments is valid.
 *
 * SPANISH: Verifica si el número de argumentos es válido.
 *
 * @param argc   The number of arguments. /
 *               El número de argumentos.
 *
 * @returns int
 *
 * - Returns 0 if the number of arguments is valid.
 *   Devuelve 0 si el número de argumentos es válido.
 *
 * - Returns -1 otherwise.
 *   Devuelve -1 en caso contrario.
 */
int	ft_checker_number_args(int argc)
{
	if (argc < 2)
	{
		ft_putstr_error("Error\n Function: ft_checker_number_args\n"
			"	Invalid number of arguments.\n");
		return (-1);
	}
	return (0);
}
