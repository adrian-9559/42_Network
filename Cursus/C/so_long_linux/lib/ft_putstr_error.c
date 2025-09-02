/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:41:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/08/31 12:00:45 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../so_long.h"

/*
 * ENGLISH: Outputs a string to the standard error output.
 *
 * SPANISH: Envía una cadena a la salida de error estándar.
 *
 * @param str   The string to output. /
 *              La cadena a enviar.
 *
 * @returns 0 on success, -1 on failure. /
 *          0 en caso de éxito, -1 en caso de error.
 */
int	ft_putstr_error(const char *str)
{
	if (!str)
	{
		if (ft_putstr_error("Error: NULL string\n") == -1)
			return (-1);
		return (0);
	}
	while (*str)
	{
		if (ft_putchar_error(*str) == -1)
		{
			ft_putchar_error('\n');
			return (-1);
		}
		str++;
	}
	return (0);
}
